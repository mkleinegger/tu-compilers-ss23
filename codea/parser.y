%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "type.h"
#include "tree.h"
#include "code_generator.h"

void yyerror(char const*);

extern int yylex();

extern void burm_reduce(NODEPTR_TYPE, int);
extern void burm_label(NODEPTR_TYPE);

%}

%token OBJECT INT CLASS END RETURN COND CONTINUE BREAK NOT OR NEW NULLTERM ID NUM
%token LEFTASSIGN RIGHTASSIGN
%token ';' '(' ',' ')' '-' '+' '*' '>' '#'
%left  '+'
%left  '*'
%left  '-'
%left  '>'
%left  '#'

%start Start

@autoinh ids
@autosyn tree

@attributes { char *name; int lineNr; } ID
@attributes { long value; } NUM
@attributes { struct type_t type; } Type
@attributes { struct type_t typeIn; struct type_t typeOut;} OptType
@attributes { struct node_t *names; } Start
@attributes { struct node_t *namesIn; struct node_t *namesOut; char *className; meth_node_t* inImplList; meth_node_t* outImplList; } MemberStart
@attributes { struct node_t *out; } Selector
@attributes { struct node_t *in; struct node_t *out; meth_node_t* inImplList; meth_node_t* outImplList; } Program Class
@attributes { struct node_t *in; struct node_t *out; char *className; meth_node_t* inImplList; meth_node_t* outImplList; } OptMember Member
@attributes { struct node_t *in; struct type_t type; } OptGuarded
@attributes { struct node_t *in; struct type_t type; tree_t *tree; } Return Conditions Guarded
@attributes { struct node_t *in; struct node_t *out; struct type_t type; } Par Stats  
@attributes { struct node_t *in; struct node_t *out; struct type_t type; tree_t *tree; } Stat  
@attributes { struct node_t *in; struct node_t *out; struct type_t typeIn; struct type_t typeOut; } Pars
@attributes { struct node_t *ids; struct type_t type; } RepExpr
@attributes { struct node_t *ids; struct type_t type; tree_t *tree; } Expr Term NotMinus PlusTerm MulTerm OrTerm Negations

@traversal @lefttoright @postorder visibilityCheck
@traversal @lefttoright @postorder typeCheck

@traversal @preorder reg
@traversal @postorder gen
@traversal @postorder burm

%%
Start           : Program
                @{ 
                    @i @Start.0.names@ = @Program.0.out@;
	                @i @Program.0.in@ = @Start.0.names@;

                    @i @Program.0.inImplList@ = newImplList();
                    @gen generateClassTable(@Program.0.out@, @Program.0.outImplList@);
                @}
                ;

Program         :        
                @{
                    @i @Program.0.out@ = newList();  

                    @i @Program.0.outImplList@ = @Program.0.inImplList@;
                @}
                | Program Selector ';'
                @{
                    @i @Program.0.out@ = mergeDev(@Program.1.out@, @Selector.0.out@, "merge Program with Selector");
                    @i @Program.1.in@ = @Program.0.in@;

                    @i @Program.1.inImplList@ = @Program.0.inImplList@;
                    @i @Program.0.outImplList@ = @Program.1.outImplList@;
                @}
                | Program Class ';'
                @{
                    @i @Program.0.out@ = mergeDev(@Program.1.out@, @Class.0.out@, "merge Program with Class");
                    @i @Program.1.in@ = @Program.0.in@;
                    @i @Class.0.in@ = @Program.0.in@;

                    @i @Program.1.inImplList@ = @Program.0.inImplList@;
                    @i @Class.0.inImplList@ = @Program.1.outImplList@;
                    @i @Program.0.outImplList@ = @Class.0.outImplList@;
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

                    @i @MemberStart.0.className@ = @ID.name@;
                    @i @MemberStart.0.inImplList@ = @Class.0.inImplList@;
                    @i @Class.0.outImplList@ = @MemberStart.0.outImplList@;
                @}
                ;

MemberStart     : OptMember
                @{
                    @i @MemberStart.0.namesOut@ = mergeDev(@MemberStart.0.namesIn@, @OptMember.0.out@, "merge MemberStart with OptMember");
                    @i @OptMember.0.in@ = @MemberStart.0.namesOut@;

                    @i @OptMember.0.className@ = @MemberStart.0.className@;
                    @i @OptMember.0.inImplList@ = @MemberStart.0.inImplList@;
                    @i @MemberStart.0.outImplList@ = @OptMember.0.outImplList@;
                @}
                ;

OptMember       :
                @{
                    @i @OptMember.0.out@ = newList();

                    @i @OptMember.0.outImplList@ = @OptMember.0.inImplList@;
                @}
	            | OptMember Member ';'
                @{
                    @i @OptMember.0.out@ = mergeDev(@OptMember.1.out@, @Member.0.out@, "merge OptMember with Member");
                    @i @OptMember.1.in@ = @OptMember.0.in@;
                    @i @Member.0.in@ = @OptMember.1.in@;

                    @i @OptMember.1.className@ = @OptMember.0.className@;
                    @i @OptMember.1.inImplList@ = @OptMember.0.inImplList@;
                    @i @Member.0.className@ = @OptMember.0.className@;
                    @i @Member.0.inImplList@ = @OptMember.1.outImplList@;
                    @i @OptMember.0.outImplList@ = @Member.0.outImplList@;
                @}
                ;

Member          : Type ID /* Objektvariablendefinition */
                @{
   	                @i @Member.0.out@ = addDev(newList(), @ID.name@, @Type.type@, KIND_CLASS_VARIABLE, @ID.lineNr@, "add Classvariable with ID");

                    @i @Member.0.outImplList@ = @Member.0.inImplList@;
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

                    @i @Member.0.outImplList@ = addImpl(@Member.0.inImplList@, @Member.0.className@, @ID.name@);
                    @burm @revorder(1) generateMethodeLabel(@Member.0.className@, @ID.name@);
                    @burm {
                        if(@Return.0.tree@ != NULL) {         
                            burm_label(@Return.0.tree@); 
                            burm_reduce(@Return.0.tree@, 1); 
                        }
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
                    
                    @burm {
                        if(@Stat.0.tree@ != NULL) {
                            burm_label(@Stat.0.tree@); 
                            burm_reduce(@Stat.0.tree@, 1); 
                        }
                    }
                @}
                ;

Stat            : Return
                @{
                    @i @Return.0.in@ = @Stat.0.in@;
                    @i @Return.0.type@ = @Stat.0.type@;
                    @i @Stat.0.out@ = @Stat.0.in@;

                    @i @Stat.0.tree@ = @Return.0.tree@;
                @}
                | Conditions
                @{
                    @i @Conditions.0.in@ = @Stat.0.in@;
                    @i @Conditions.0.type@ = @Stat.0.type@;
                    @i @Stat.0.out@ = @Stat.0.in@;

                    @i @Stat.0.tree@ = NULL;
                @}
                | Type ID LEFTASSIGN Expr /* Variablendefinition */
                @{
                    @i @Expr.0.ids@ = @Stat.0.in@;
                    @i @Stat.0.out@ = addDev(duplicate(@Expr.0.ids@), @ID.name@, @Type.0.type@, KIND_VARIABLE, @ID.lineNr@, "Type assignment ID in Stat");
                    @typeCheck checkForEqualType(@Type.0.type@, @Expr.0.type@);

                    @i @Stat.0.tree@ = NULL;
                @}
                | ID LEFTASSIGN Expr /* Zuweisung */
                @{
                    @i @Expr.0.ids@ = @Stat.0.in@;
                    @i @Stat.0.out@ = @Stat.0.in@;
                    @visibilityCheck isVisibleForUse(@Stat.0.in@, @ID.name@, @ID.lineNr@);
                    @typeCheck checkForEqualType(getType(@Stat.0.in@, @ID.name@, @ID.lineNr@), @Expr.0.type@);

                    @i @Stat.0.tree@ = NULL;
                @}
                | Expr /* Ausdrucksanweisung */
                @{
                    @i @Expr.0.ids@ = @Stat.0.in@ ;
                    @i @Stat.0.out@ = @Stat.0.in@ ;

                    @i @Stat.0.tree@ = NULL;
                @}
                ;

Return          : RETURN Expr 
                @{
                    @i @Expr.0.ids@ = @Return.0.in@;
                    @typeCheck checkForEqualType(@Return.0.type@, @Expr.0.type@);

                    @i @Return.0.tree@ = createNode(OP_RETURN, @Expr.0.tree@, NULL);
                    @reg {
                        @Return.0.tree@->regStor = getFirstRegister(); 
                        @Expr.0.tree@->regStor = @Return.0.tree@->regStor;
                    }
                @}
                ;

Conditions      : COND OptGuarded END
                @{
                    @i @OptGuarded.0.in@ = @Conditions.0.in@;
                    @i @OptGuarded.0.type@ = @Conditions.0.type@;

                    @i @Conditions.0.tree@ = NULL;
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

                    @i @Guarded.0.tree@ = NULL;
                @}
                | Expr RIGHTASSIGN Stats ContinueOrBreak 
                @{
                    @i @Expr.0.ids@ = @Guarded.0.in@ ;
                    @i @Stats.0.type@ = @Guarded.0.type@; 
                    @i @Stats.0.in@ = duplicate(@Guarded.0.in@);
                    @typeCheck checkForEqualType(@Expr.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @Guarded.0.tree@ = NULL;
                @}
                ;

ContinueOrBreak : CONTINUE
	            | BREAK
	            ;

Expr            : Negations
                @{
                    @i @Negations.0.ids@ = @Expr.0.ids@;
                    @i @Expr.0.type@ = @Negations.0.type@;
                    
                    @i @Expr.0.tree@ = @Negations.0.tree@; 
                    @reg @Negations.0.tree@->regStor = @Expr.0.tree@->regStor;   
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

                    @i @Expr.0.tree@ = createNode(OP_ADD, @Term.0.tree@, @PlusTerm.0.tree@);
                    @reg {
                        @Term.0.tree@->regStor = @Expr.0.tree@->regStor; 
                        @PlusTerm.0.tree@->regStor = getNextRegister(@Expr.0.tree@->regStor);
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

                    @i @Expr.0.tree@ = createNode(OP_MUL, @Term.0.tree@, @MulTerm.0.tree@);
                    @reg {
                        @Term.0.tree@->regStor = @Expr.0.tree@->regStor; 
                        @MulTerm.0.tree@->regStor = getNextRegister(@Expr.0.tree@->regStor);
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

                    @i @Expr.0.tree@ = createNode(OP_OR, @Term.0.tree@, @OrTerm.0.tree@);
                    @reg {
                        @Term.0.tree@->regStor = @Expr.0.tree@->regStor; 
                        @OrTerm.0.tree@->regStor = getNextRegister(@Expr.0.tree@->regStor);
                    }
                @}
                | Term '#' Term
                @{
                    @i @Term.0.ids@ = @Expr.0.ids@;
                    @i @Term.1.ids@ = @Expr.0.ids@;
                    @i @Expr.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck checkForEqualType(@Term.0.type@, @Term.1.type@);

                    @i @Expr.0.tree@ = createNode(OP_NOT_EQUAL, @Term.0.tree@, @Term.1.tree@);
                    @reg {
                        @Term.0.tree@->regStor = @Expr.0.tree@->regStor; 
                        @Term.1.tree@->regStor = getNextRegister(@Expr.0.tree@->regStor);
                    }
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

                    @i @Expr.0.tree@ = createNode(OP_GREATER, @Term.0.tree@, @Term.1.tree@);
                    @reg {
                        @Term.0.tree@->regStor = @Expr.0.tree@->regStor; 
                        @Term.1.tree@->regStor = getNextRegister(@Expr.0.tree@->regStor);
                    }
                @}
                | NEW ID
                @{
                    @i @Expr.0.type@ = newTypeWith(TYPE_OBJECT, TYPE_NONE);
                    @visibilityCheck isVisible(@Expr.0.ids@, @ID.name@, KIND_CLASS, @ID.lineNr@);

                    @i @Expr.0.tree@ = NULL;
                @}	
                ;

Negations       : Term
                @{
                    @i @Term.0.ids@ = @Negations.0.ids@;
                    @i @Negations.0.type@ = @Term.0.type@;
                    
                    @i @Negations.0.tree@ = @Term.0.tree@;
                    @reg @Term.0.tree@->regStor = @Negations.0.tree@->regStor;
                @}
                | NOT Negations
                @{
                    @i @Negations.1.ids@ = @Negations.0.ids@;
                    @i @Negations.0.type@ = @Negations.1.type@;
                    @typeCheck checkForEqualType(@Negations.1.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @Negations.0.tree@ = createNode(OP_NOT, @Negations.1.tree@, NULL);
                    @reg @Negations.1.tree@->regStor = @Negations.0.tree@->regStor;
                @}
                | '-' Negations
                @{
                    @i @Negations.1.ids@ = @Negations.0.ids@;
                    @i @Negations.0.type@ = @Negations.1.type@;
                    @typeCheck checkForEqualType(@Negations.1.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @Negations.0.tree@ = createNode(OP_NEG, @Negations.1.tree@, NULL);
                    @reg @Negations.1.tree@->regStor = @Negations.0.tree@->regStor;
                @}
                ;

PlusTerm        : '+' Term 
                @{
                    @i @Term.0.ids@ = @PlusTerm.0.ids@;
                    @i @PlusTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @PlusTerm.0.tree@ = @Term.0.tree@ ; 
                    @reg @Term.0.tree@->regStor = @PlusTerm.0.tree@->regStor ;
                @}
	            | '+' Term PlusTerm
                @{
                    @i @PlusTerm.1.ids@ = @PlusTerm.0.ids@;
                    @i @PlusTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @i @Term.0.ids@ = @PlusTerm.0.ids@;
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@PlusTerm.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }

                    @i @PlusTerm.0.tree@ = createNode(OP_ADD, @Term.0.tree@, @PlusTerm.1.tree@);
                    @reg {
                        @Term.0.tree@->regStor = @PlusTerm.0.tree@->regStor; 
                        @PlusTerm.1.tree@->regStor = getNextRegister(@PlusTerm.0.tree@->regStor);
                    }
                @}
	            ;

MulTerm         : '*' Term
                @{      
                    @i @Term.0.ids@ = @MulTerm.0.ids@;
                    @i @MulTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));    

                    @i @MulTerm.0.tree@ = @Term.0.tree@; 
                    @reg @Term.0.tree@->regStor = @MulTerm.0.tree@->regStor;                
                @}
                | '*' Term MulTerm
                @{
                    @i @MulTerm.1.ids@ = @MulTerm.0.ids@;
                    @i @MulTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @i @Term.0.ids@ = @MulTerm.0.ids@;
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@MulTerm.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }

                    @i @MulTerm.0.tree@ = createNode(OP_MUL, @Term.0.tree@, @MulTerm.1.tree@);
                    @reg {
                        @Term.0.tree@->regStor = @MulTerm.0.tree@->regStor; 
                        @MulTerm.1.tree@->regStor = getNextRegister(@MulTerm.0.tree@->regStor);
                    }
                @}
                ;

OrTerm          : OR Term
                @{      
                    @i @Term.0.ids@ = @OrTerm.0.ids@;
                    @i @OrTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @OrTerm.0.tree@ = @Term.0.tree@; 
                    @reg @Term.0.tree@->regStor = @OrTerm.0.tree@->regStor;      
                @}
                | OR Term OrTerm
                @{
                    @i @OrTerm.1.ids@ = @OrTerm.0.ids@;
                    @i @OrTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    @i @Term.0.ids@ = @OrTerm.0.ids@;
                    @typeCheck {
                        checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                        checkForEqualType(@OrTerm.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));
                    }

                    @i @OrTerm.0.tree@ = createNode(OP_OR, @Term.0.tree@, @OrTerm.1.tree@);
                    @reg {
                        @Term.0.tree@->regStor = @OrTerm.0.tree@->regStor; 
                        @OrTerm.1.tree@->regStor = getNextRegister(@OrTerm.0.tree@->regStor);
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

                    @i @Term.0.tree@ = @Expr.0.tree@;
                    @reg @Expr.0.tree@->regStor = @Term.0.tree@->regStor;   
                @}
                | NUM 
                @{
                    @i @Term.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);

                    @i @Term.0.tree@ = createNumericalLeaf(@NUM.value@);
                @}
                | NULLTERM
                @{
                    @i @Term.0.type@ = newTypeWith(TYPE_OBJECT, TYPE_NONE);

                    @i @Term.0.tree@ = createNULLLeaf();
                @}
                | ID /* lesender Zugriff */
                @{
                    @i @Term.0.type@ = getType(@Term.0.ids@, @ID.name@, @ID.lineNr@);
                    @visibilityCheck isVisibleForUse(@Term.0.ids@, @ID.name@, @ID.lineNr@);

                    @i @Term.0.tree@ = createIdentifierLeaf(@ID.name@, getKindOfName(@Term.ids@, @ID.name@), getParameterIndex(@Term.ids@, @ID.name@), getClassVarOffset(@Term.ids@, @ID.name@));
                @}
                | ID '(' Expr RepExpr ')' /* Aufruf */
                @{
                    @i @Expr.0.ids@ = @Term.0.ids@;
                    @i @RepExpr.0.ids@ = @Term.0.ids@;
                    @i @RepExpr.0.type@ = newType();
                    @i @Term.0.type@ = getType(@Term.0.ids@, @ID.name@, @ID.lineNr@);
                    @visibilityCheck isVisible(@Term.0.ids@, @ID.name@, KIND_SELECTOR, @ID.lineNr@);

                    @i @Term.0.tree@ = NULL;
                @}
                ;

%%



int main(void)
{
    int ret = yyparse();
    return ret;
}

