%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "type.h"

void yyerror(char const*);

extern int yylex();

%}

%token OBJECT INT CLASS END RETURN COND CONTINUE BREAK NOT OR NEW NULLTERM ID NUM
%token LEFTASSIGN RIGHTASSIGN
%token ';' '(' ',' ')' '-' '+' '*' '>' '#'

%start Start

@autoinh ids
@attributes { char *name; int lineNr; } ID
@attributes { struct type_t type; } Type
@attributes { struct type_t typeIn; struct type_t typeOut;} OptType
@attributes { struct node_t *names; } Start
@attributes { struct node_t *namesIn; struct node_t *namesOut; } MemberStart
@attributes { struct node_t *out; } Selector
@attributes { struct node_t *in; struct node_t *out; } Program Class OptMember Member
@attributes { struct node_t *in; struct type_t type; } Return Conditions OptGuarded Guarded
@attributes { struct node_t *in; struct node_t *out; struct type_t type; } Par Stats Stat  
@attributes { struct node_t *in; struct node_t *out; struct type_t typeIn; struct type_t typeOut; } Pars
@attributes { struct node_t *ids; struct type_t type; } Expr RepExpr Term NotMinus PlusTerm MulTerm OrTerm

@traversal @lefttoright @postorder visibilityCheck
@traversal @lefttoright @postorder typeCheck

%%
Start           : Program
                @{ 
                    @i @Start.0.names@ = @Program.0.out@;
	                @i @Program.0.in@ = @Start.0.names@;
                @}
                ;

Program         :        
                @{
                    @i @Program.0.out@ = newList();  
                @}
                | Program Selector ';'
                @{
                    @i @Program.0.out@ = mergeDev(@Program.1.out@, @Selector.0.out@, "merge Program with Selector");
                    @i @Program.1.in@ = @Program.0.in@;
                @}
                | Program Class ';'
                @{
                    @i @Program.0.out@ = mergeDev(@Program.1.out@, @Class.0.out@, "merge Program with Class");
                    @i @Program.1.in@ = @Program.0.in@;
                    @i @Class.0.in@ = @Program.0.in@;
                @}
                ;

Selector        : Type ID '(' OBJECT OptType ')'
	            @{
                    @i @OptType.0.typeIn@ = typeParamsAppend(@Type.0.type@, TYPE_OBJECT);
	                @i @Selector.0.out@ = addDev(newList(), @ID.name@, @OptType.0.typeOut@, KIND_SELECTOR, @ID.lineNr@, "add Selector with ID") ;
	            @}
                ;

OptType         :
                @{
	                @i @OptType.0.typeOut@ = @OptType.0.typeIn@;
                @}
                | OptType ',' Type
                @{
                    @i @OptType.1.typeIn@ = @OptType.0.typeIn@;
                    @i @OptType.0.typeOut@ = typeParamsAppend(@OptType.1.typeOut@, @Type.0.type@.type);
                @}
                ;

Type            : INT @{ @i @Type.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE); @}
                | OBJECT @{ @i @Type.0.type@ = newTypeWith(TYPE_OBJECT, TYPE_NONE); @}
                ;

Class           : CLASS ID MemberStart END /* Klassendefinition */
                @{
                    @i @Class.0.out@ = addDev(newList(), @ID.name@, newType(), KIND_CLASS, @ID.lineNr@, "add Class with ID");
                    @i @MemberStart.0.namesIn@ = duplicate(@Class.0.in@);
                @}
                ;

MemberStart     : OptMember
                @{
                    @i @MemberStart.0.namesOut@ = mergeDev(@MemberStart.0.namesIn@, @OptMember.0.out@, "merge MemberStart with OptMember");
                    @i @OptMember.0.in@ = @MemberStart.0.namesOut@;
                @}
                ;

OptMember       :
                @{
                    @i @OptMember.0.out@ = newList();
                @}
	            | OptMember Member ';'
                @{
                    @i @OptMember.0.out@ = mergeDev(@OptMember.1.out@, @Member.0.out@, "merge OptMember with Member");
                    @i @OptMember.1.in@ = @OptMember.0.in@;
                    @i @Member.0.in@ = @OptMember.1.in@;
                @}
                ;

Member          : Type ID /* Objektvariablendefinition */
                @{
   	                @i @Member.0.out@ = addDev(newList(), @ID.name@, @Type.type@, KIND_CLASS_VARIABLE, @ID.lineNr@, "add Classvariable with ID");
                @}
                | Type ID '(' Par Pars ')' Stats Return END /* Methodenimplementierung */
                @{
                    @i @Member.0.out@ = newList();
                    @i @Par.0.in@ = duplicate(@Member.0.in@);
        	        @i @Pars.0.in@ = @Par.0.out@;
                    @i @Pars.0.typeIn@ = typeParamsAppend(@Type.0.type@, @Par.0.type@.type);
                    @i @Stats.0.in@ = @Pars.0.out@;
                    @i @Stats.0.type@ = @Type.0.type@;
                    @i @Return.0.in@ = @Stats.0.out@;
                    @i @Return.0.type@ = @Type.0.type@;
                    @visibilityCheck isVisible(@Member.0.in@, @ID.name@, KIND_SELECTOR, @ID.lineNr@);
                    @typeCheck {
                        checkForEqualType(@Type.0.type@, getType(@Member.0.in@, @ID.name@, @ID.lineNr@));
                        checkForEqualParamsType(@Pars.0.typeOut@, getType(@Member.0.in@, @ID.name@, @ID.lineNr@));
                    }
                @}
                ;

Pars            :         
                @{
                    @i @Pars.0.out@ = @Pars.0.in@;
                    @i @Pars.0.typeOut@ = @Pars.0.typeIn@;
                @}
                | Pars ',' Par
                @{
                    @i @Pars.1.in@ = @Pars.0.in@;
                    @i @Pars.1.typeIn@ = @Pars.0.typeIn@;
                    @i @Par.0.in@ = @Pars.1.out@;
                    @i @Pars.0.out@ = @Par.0.out@;
                    @i @Pars.0.typeOut@ = typeParamsAppend(@Pars.1.typeOut@, @Par.0.type@.type);
                @}
                ;

Par             : Type ID  /* Parameterdefinition */
                @{
                    @i @Par.0.out@ = addDev(@Par.0.in@, @ID.name@, @Type.0.type@, KIND_PARAMETER, @ID.lineNr@, "add Parameter with ID");
                    @i @Par.0.type@ = @Type.0.type@;
                @}
                ;

Stats           : 
                @{
                    @i @Stats.0.out@ = @Stats.0.in@;
                @}
                | Stats Stat ';'
                @{
                    @i @Stats.1.in@ = @Stats.0.in@;
                    @i @Stats.1.type@ = @Stats.0.type@;
                    @i @Stat.0.in@ = @Stats.1.out@;
                    @i @Stat.0.type@ = @Stats.0.type@;
                    @i @Stats.0.out@ = @Stat.0.out@;
                @}
                ;

Stat            : Return
                @{
                    @i @Return.0.in@ = @Stat.0.in@;
                    @i @Return.0.type@ = @Stat.0.type@;
                    @i @Stat.0.out@ = @Stat.0.in@;
                @}
                | Conditions
                @{
                    @i @Conditions.0.in@ = @Stat.0.in@;
                    @i @Conditions.0.type@ = @Stat.0.type@;
                    @i @Stat.0.out@ = @Stat.0.in@;
                @}
                | Type ID LEFTASSIGN Expr /* Variablendefinition */
                @{
                    @i @Expr.0.ids@ = @Stat.0.in@;
                    @i @Stat.0.out@ = addDev(duplicate(@Expr.0.ids@), @ID.name@, @Type.0.type@, KIND_VARIABLE, @ID.lineNr@, "Type assignment ID in Stat");
                    @typeCheck checkForEqualType(@Type.0.type@, @Expr.0.type@);
                @}
                | ID LEFTASSIGN Expr /* Zuweisung */
                @{
                    @i @Expr.0.ids@ = @Stat.0.in@;
                    @i @Stat.0.out@ = @Stat.0.in@;
                    @visibilityCheck isVisibleForUse(@Stat.0.in@, @ID.name@, @ID.lineNr@);
                    @typeCheck checkForEqualType(getType(@Stat.0.in@, @ID.name@, @ID.lineNr@), @Expr.0.type@);
                @}
                | Expr /* Ausdrucksanweisung */
                @{
                    @i @Expr.0.ids@ = @Stat.0.in@ ;
                    @i @Stat.0.out@ = @Stat.0.in@ ;
                @}
                ;

Return          : RETURN Expr 
                @{
                    @i @Expr.0.ids@ = @Return.0.in@;
                    @typeCheck checkForEqualType(@Return.0.type@, @Expr.0.type@);
                @}
                ;

Conditions      : COND OptGuarded END
                @{
                    @i @OptGuarded.0.in@ = @Conditions.0.in@;
                    @i @OptGuarded.0.type@ = @Conditions.0.type@;
                @}
                ;

OptGuarded      :
	            | OptGuarded Guarded ';'
                @{
                    @i @OptGuarded.1.in@ = @OptGuarded.0.in@;
                    @i @OptGuarded.1.type@ = @OptGuarded.0.type@;
                    @i @Guarded.0.in@ = @OptGuarded.0.in@;
                    @i @Guarded.0.type@ = @OptGuarded.0.type@;                
                @}
	            ;

Guarded         : RIGHTASSIGN Stats ContinueOrBreak 
                @{
                    @i @Stats.0.type@ = @Guarded.0.type@; 
                    @i @Stats.0.in@ = duplicate(@Guarded.0.in@);
                @}
                | Expr RIGHTASSIGN Stats ContinueOrBreak 
                @{
                    @i @Expr.0.ids@ = @Guarded.0.in@ ;
                    @i @Stats.0.type@ = @Guarded.0.type@; 
                    @i @Stats.0.in@ = duplicate(@Guarded.0.in@);
                    @typeCheck checkForEqualType(@Expr.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                @}
                ;

ContinueOrBreak : CONTINUE
	            | BREAK
	            ;

Expr            : Term
                @{
                    @i @Term.0.ids@ = @Expr.0.ids@;
                    @i @Expr.0.type@ = @Term.0.type@;
                @}
                | Negations Term
                @{
                    @i @Term.0.ids@ = @Expr.0.ids@;
                    @i @Expr.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                @}
                | Term PlusTerm
                @{
                    @i @Term.0.ids@ = @Expr.0.ids@;
                    @i @PlusTerm.0.ids@ = @Expr.0.ids@;
                    @i @Expr.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@PlusTerm.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }
                @}
                | Term MulTerm
                @{
                    @i @Term.0.ids@ = @Expr.0.ids@;
                    @i @MulTerm.0.ids@ = @Expr.0.ids@;
                    @i @Expr.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@MulTerm.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }
                @}
                | Term OrTerm
                @{
                    @i @Term.0.ids@ = @Expr.0.ids@;
                    @i @OrTerm.0.ids@ = @Expr.0.ids@;
                    @i @Expr.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@OrTerm.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }
                @}
                | Term '#' Term
                @{
                    @i @Term.0.ids@ = @Expr.0.ids@;
                    @i @Term.1.ids@ = @Expr.0.ids@;
                    @i @Expr.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck checkForEqualType(@Term.0.type@, @Term.1.type@);
                @}
                | Term '>' Term
                @{
                    @i @Term.0.ids@ = @Expr.0.ids@;
                    @i @Term.1.ids@ = @Expr.0.ids@;
                    @i @Expr.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@Term.1.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }
                @}
                | NEW ID
                @{
                    @i @Expr.0.type@ = newTypeWith(TYPE_OBJECT, TYPE_NONE);
                    @visibilityCheck isVisible(@Expr.0.ids@, @ID.name@, KIND_CLASS, @ID.lineNr@);
                @}	
                ;

Negations       : NOT
                | '-'
                | Negations NOT
                | Negations '-'
                ;

PlusTerm        : '+' Term 
                @{
                    @i @Term.0.ids@ = @PlusTerm.0.ids@;
                    @i @PlusTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                @}
	            | PlusTerm '+' Term
                @{
                    @i @PlusTerm.1.ids@ = @PlusTerm.0.ids@;
                    @i @PlusTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @i @Term.0.ids@ = @PlusTerm.0.ids@;
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@PlusTerm.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }
                @}
	            ;

MulTerm         : '*' Term
                @{      
                    @i @Term.0.ids@ = @MulTerm.0.ids@;
                    @i @MulTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));                    
                @}
                | MulTerm '*' Term
                @{
                    @i @MulTerm.1.ids@ = @MulTerm.0.ids@;
                    @i @MulTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @i @Term.0.ids@ = @MulTerm.0.ids@;
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@MulTerm.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }
                @}
                ;

OrTerm          : OR Term
                @{      
                    @i @Term.0.ids@ = @OrTerm.0.ids@;
                    @i @OrTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                @}
                | OrTerm OR Term
                @{
                    @i @OrTerm.1.ids@ = @OrTerm.0.ids@;
                    @i @OrTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @i @Term.0.ids@ = @OrTerm.0.ids@;
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@OrTerm.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }
                @}
                ;

RepExpr         :
                | RepExpr ',' Expr 
                @{
                    @i @RepExpr.1.ids@ = @RepExpr.0.ids@;
                    @i @RepExpr.1.type@ = @RepExpr.0.type@;
                    @i @Expr.0.ids@ = @RepExpr.0.ids@;
                @}
                ;

Term            : '(' Expr ')'
                @{
                    @i @Expr.0.ids@ = @Term.0.ids@;
                    @i @Term.0.type@ = @Expr.0.type@;
                @}
                | NUM 
                @{
                    @i @Term.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                @}
                | NULLTERM
                @{
                    @i @Term.0.type@ = newTypeWith(TYPE_OBJECT, TYPE_NONE);
                @}
                | ID /* lesender Zugriff */
                @{
                    @i @Term.0.type@ = getType(@Term.0.ids@, @ID.name@, @ID.lineNr@);
                    @visibilityCheck isVisibleForUse(@Term.0.ids@, @ID.name@, @ID.lineNr@);
                @}
                | ID '(' Expr RepExpr ')' /* Aufruf */
                @{
                    @i @Expr.0.ids@ = @Term.0.ids@;
                    @i @RepExpr.0.ids@ = @Term.0.ids@;
                    @i @RepExpr.0.type@ = newType();
                    @i @Term.0.type@ = getType(@Term.0.ids@, @ID.name@, @ID.lineNr@);
                    @visibilityCheck isVisible(@Term.0.ids@, @ID.name@, KIND_SELECTOR, @ID.lineNr@);
                @}
                ;

%%



int main(void)
{
    int ret = yyparse();
    return ret;
}

