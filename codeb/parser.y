%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "type.h"
#include "code_generator.h"

void yyerror(char const*);

extern int yylex();

extern void burm_reduce(NODEPTR_TYPE, int);
extern void burm_label(NODEPTR_TYPE);

long globalGuardCounter = 0;

char* prepareLabelString(char* type, char* classname, char* functionname, int counter)
{
    char *label = calloc(strlen(type) + strlen(classname) + strlen(functionname) + 4 + counter, sizeof(char));
    sprintf(label, "%s_%s_%s_%d", type, classname, functionname, counter);
    return label;
}

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
@attributes { struct node_t *namesIn; struct node_t *namesOut; char *className; class_node_t* classListIn; class_node_t* classListOut; } MemberStart
@attributes { struct node_t *out; } Selector
@attributes { struct node_t *in; struct node_t *out; class_node_t* classListIn; class_node_t* classListOut; } Program Class
@attributes { struct node_t *in; struct node_t *out; char *className; class_node_t* classListIn; class_node_t* classListOut; } OptMember Member
@attributes { struct node_t *in; struct type_t type; class_node_t* classList; char *className; char *functionName; long condCounterIn; long condCounterOut; } OptGuarded 
@attributes { struct node_t *in; struct type_t type; class_node_t* classList; char *className; char *functionName; long condCounterIn; long condCounterOut; } StartGuarded 
@attributes { struct node_t *in; struct type_t type; tree_t *tree; class_node_t *classList; } Return 
@attributes { struct node_t *in; struct type_t type; tree_t *tree; class_node_t* classList; char *className; char *functionName; long condCounterIn; long condCounterOut; } Conditions Guarded 
@attributes { struct node_t *in; struct node_t *out; struct type_t type; } Par 
@attributes { struct node_t *in; struct node_t *out; struct type_t type; tree_t *injectionIn; class_node_t* classList; char *className; char *functionName; long condCounterIn; long condCounterOut; } Stats   
@attributes { struct node_t *in; struct node_t *out; struct type_t type; tree_t *tree; class_node_t* classList; char *className; char *functionName; long condCounterIn; long condCounterOut; } Stat  
@attributes { struct node_t *in; struct node_t *out; struct type_t typeIn; struct type_t typeOut; } Pars
@attributes { struct node_t *ids; struct type_t type; class_node_t* classList; } RepExpr
@attributes { struct node_t *ids; struct type_t type; tree_t *tree; class_node_t* classList; } Expr Term OrTerm Negations PlusTerm MulTerm 

@traversal @lefttoright @postorder visibilityCheck
@traversal @lefttoright @postorder typeCheck
@traversal @lefttoright @preorder reg
@traversal @lefttoright @postorder gen
@traversal @lefttoright @postorder burm

%%
Start           : Program
                @{ 
                    @i @Start.0.names@ = @Program.0.out@;
	                @i @Program.0.in@ = @Start.0.names@;

                    @i @Program.0.classListIn@ = newImplList();
                    @gen generateClassTable(@Program.0.out@, @Program.0.classListOut@);
                @}
                ;

Program         :        
                @{
                    @i @Program.0.out@ = newList();  

                    @i @Program.0.classListOut@ = @Program.0.classListIn@;
                @}
                | Program Selector ';'
                @{
                    @i @Program.0.out@ = merge(@Program.1.out@, @Selector.0.out@);
                    @i @Program.1.in@ = @Program.0.in@;

                    @i @Program.1.classListIn@ = @Program.0.classListIn@;
                    @i @Program.0.classListOut@ = @Program.1.classListOut@;
                @}
                | Program Class ';'
                @{
                    @i @Program.0.out@ = merge(@Program.1.out@, @Class.0.out@);
                    @i @Program.1.in@ = @Program.0.in@;
                    @i @Class.0.in@ = @Program.0.in@;

                    @i @Program.1.classListIn@ = @Program.0.classListIn@;
                    @i @Class.0.classListIn@ = @Program.1.classListOut@;
                    @i @Program.0.classListOut@ = @Class.0.classListOut@;
                @}
                ;

Selector        : Type ID '(' OBJECT OptType ')'
	            @{
                    @i @OptType.0.typeIn@ = typeParamsAppend(@Type.0.type@, TYPE_OBJECT);
	                @i @Selector.0.out@ = add(newList(), @ID.name@, @OptType.0.typeOut@, KIND_SELECTOR, @ID.lineNr@) ;
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
                    @i @Class.0.out@ = add(newList(), @ID.name@, newType(), KIND_CLASS, @ID.lineNr@);
                    @i @MemberStart.0.namesIn@ = duplicate(@Class.0.in@);

                    @i @MemberStart.0.className@ = @ID.name@;
                    @i @MemberStart.0.classListIn@ = @Class.0.classListIn@;
                    @i @Class.0.classListOut@ = @MemberStart.0.classListOut@;
                @}
                ;

MemberStart     : OptMember
                @{
                    @i @MemberStart.0.namesOut@ = merge(@MemberStart.0.namesIn@, @OptMember.0.out@);
                    @i @OptMember.0.in@ = @MemberStart.0.namesOut@;

                    @i @OptMember.0.className@ = @MemberStart.0.className@;
                    @i @OptMember.0.classListIn@ = @MemberStart.0.classListIn@;
                    @i @MemberStart.0.classListOut@ = @OptMember.0.classListOut@;
                @}
                ;

OptMember       :
                @{
                    @i @OptMember.0.out@ = newList();

                    @i @OptMember.0.classListOut@ = @OptMember.0.classListIn@;
                @}
	            | OptMember Member ';'
                @{                    
                    @i @OptMember.1.in@ = @OptMember.0.in@;
                    @i @OptMember.1.className@ = @OptMember.0.className@;
                    @i @OptMember.1.classListIn@ = @OptMember.0.classListIn@;

                    @i @Member.0.in@ = @OptMember.1.in@;
                    @i @Member.0.className@ = @OptMember.0.className@;
                    @i @Member.0.classListIn@ = @OptMember.1.classListOut@;
                  
                    @i @OptMember.0.out@ = merge(@OptMember.1.out@, @Member.0.out@);
                    @i @OptMember.0.classListOut@ = @Member.0.classListOut@;
                @}
                ;

Member          : Type ID /* Objektvariablendefinition */
                @{
   	                @i @Member.0.out@ = add(newList(), @ID.name@, @Type.type@, KIND_CLASS_VARIABLE, @ID.lineNr@);

                    @i @Member.0.classListOut@ = addClassVar(@Member.0.classListIn@, @Member.0.className@, @ID.name@);
                @}
                | Type ID '(' Par Pars ')' Stats Return END /* Methodenimplementierung */
                @{
                    @i @Member.0.out@ = newList();

                    @i @Par.0.in@ = duplicate(@Member.0.in@);
        	        @i @Pars.0.in@ = @Par.0.out@;
                    @i @Pars.0.typeIn@ = typeParamsAppend(@Type.0.type@, @Par.0.type@.type);

                    @i @Stats.0.in@ = @Pars.0.out@;
                    @i @Stats.0.type@ = @Type.0.type@;
                    @i @Stats.0.className@ = @Member.0.className@;
                    @i @Stats.0.functionName@ = @ID.name@;
                    @i @Stats.0.condCounterIn@ = 0;
                    @i @Stats.0.injectionIn@ = NULL;
                    @i @Stats.0.classList@ = @Member.0.classListOut@;

                    @i @Return.0.in@ = @Stats.0.out@;
                    @i @Return.0.type@ = @Type.0.type@;
                    @i @Return.0.classList@ = @Member.0.classListOut@;

                    @i @Member.0.classListOut@ = addImpl(@Member.0.classListIn@, @Member.0.className@, @ID.name@);

                    @visibilityCheck isVisible(@Member.0.in@, @ID.name@, KIND_SELECTOR, @ID.lineNr@);
                    @typeCheck {
                        checkForEqualType(@Type.0.type@, getType(@Member.0.in@, @ID.name@, @ID.lineNr@));
                        checkForEqualParamsType(@Pars.0.typeOut@, getType(@Member.0.in@, @ID.name@, @ID.lineNr@));
                    }

                    /* Write the method label at the beginning */
                    @burm @revorder(1) generateMethodeLabel(@Member.0.className@, @ID.name@, countLocalVarsForClassMethod(@Member.0.classListOut@, @Member.0.className@, @ID.name@));
                    
                    /* Write the code for the return statement */
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
                    @i @Par.0.out@ = add(@Par.0.in@, @ID.name@, @Type.0.type@, KIND_PARAMETER, @ID.lineNr@);
                    @i @Par.0.type@ = @Type.0.type@;
                @}
                ;

Stats           : 
                @{
                    @i @Stats.0.out@ = @Stats.0.in@;
                    @i @Stats.0.condCounterOut@ = @Stats.0.condCounterIn@;

                    /* Inject code to perform before Stat-code (guarded-rule) */
                    @burm @revorder(1) {
                        if(@Stats.0.injectionIn@ != NULL) { 
                            burm_label(@Stats.0.injectionIn@); 
                            burm_reduce(@Stats.0.injectionIn@, 1);
                        }
                    } 
                @}
                | Stats Stat ';'
                @{
                    @i @Stats.1.in@ = @Stats.0.in@;
                    @i @Stats.1.condCounterIn@ = @Stats.0.condCounterIn@;
                    @i @Stats.1.type@ = @Stats.0.type@;
                    @i @Stats.1.injectionIn@ = NULL; /* not needed */
                    @i @Stats.1.className@ = @Stats.0.className@;
                    @i @Stats.1.functionName@ = @Stats.0.functionName@;
                    @i @Stats.1.classList@ = @Stats.0.classList@;

                                       
                    @i @Stat.0.in@ = @Stats.1.out@;
                    @i @Stat.0.condCounterIn@ = @Stats.1.condCounterOut@;
                    @i @Stat.0.type@ = @Stats.0.type@;
                    @i @Stats.0.out@ = @Stat.0.out@;
                    @i @Stat.0.className@ = @Stats.0.className@;
                    @i @Stat.0.functionName@ = @Stats.0.functionName@;
                    @i @Stat.0.classList@ = @Stats.0.classList@;
                    
                    @i @Stats.0.condCounterOut@ = @Stat.0.condCounterOut@;

                    /* Inject code to perform before Stat-code (guarded-rule) */
                    @burm @revorder(1) {
                         if(@Stats.0.injectionIn@ != NULL) { 
                            burm_label(@Stats.0.injectionIn@); 
                            burm_reduce(@Stats.0.injectionIn@, 1);
                        }
                    } 

                    /* Produce code for the Stat-rule*/
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
                    @i @Return.0.classList@ = @Stat.0.classList@;
                    
                    @i @Stat.0.out@ = @Stat.0.in@;
                    @i @Stat.0.condCounterOut@ = @Stat.0.condCounterIn@;
                    @i @Stat.0.tree@ = @Return.0.tree@;
                @}
                | Conditions
                @{
                    @i @Conditions.0.in@ = @Stat.0.in@;
                    @i @Conditions.0.type@ = @Stat.0.type@;
                    @i @Conditions.0.className@ = @Stat.0.className@;
                    @i @Conditions.0.functionName@ = @Stat.0.functionName@;
                    @i @Conditions.0.condCounterIn@ = @Stat.0.condCounterIn@;
                    @i @Conditions.0.classList@ = @Stat.0.classList@;

                    @i @Stat.0.out@ = @Stat.0.in@;
                    @i @Stat.0.condCounterOut@ = @Conditions.0.condCounterOut@;
                    @i @Stat.0.tree@ = NULL; /* not needed */
                @}
                | Type ID LEFTASSIGN Expr /* Variablendefinition */
                @{
                    @i @Expr.0.ids@ = @Stat.0.in@;
                    @i @Expr.0.classList@ = addLocalVar(@Stat.0.classList@, @Stat.0.className@, @Stat.0.functionName@, @ID.name@);

                    @i @Stat.0.condCounterOut@ = @Stat.0.condCounterIn@;
                    @i @Stat.0.out@ = add(duplicate(@Expr.0.ids@), @ID.name@, @Type.0.type@, KIND_VARIABLE, @ID.lineNr@);

                    @typeCheck checkForEqualType(@Type.0.type@, @Expr.0.type@);
                    
                    @i @Stat.0.tree@ = createNode(OP_ASSIGN, createIdentifierLeaf(@ID.name@, getKindOfName(@Stat.0.out@, @ID.name@), getParameterIndex(@Stat.0.out@, @ID.name@), getLocalVarOffset(@Stat.0.out@, @ID.name@)), @Expr.0.tree@);
                    @reg {
                        @Stat.0.tree@->regStor = getFirstRegister(); 
                        @Expr.0.tree@->regStor = @Stat.0.tree@->regStor;
                    }
                @}
                | ID LEFTASSIGN Expr /* Zuweisung */
                @{
                    @i @Expr.0.ids@ = @Stat.0.in@;
                    @i @Expr.0.classList@ = @Stat.0.classList@;

                    @i @Stat.0.out@ = @Stat.0.in@;
                    @i @Stat.0.condCounterOut@ = @Stat.0.condCounterIn@;
                   
                    @visibilityCheck isVisibleForUse(@Stat.0.in@, @ID.name@, @ID.lineNr@);
                    @typeCheck checkForEqualType(getType(@Stat.0.in@, @ID.name@, @ID.lineNr@), @Expr.0.type@);

                    @i @Stat.0.tree@ = createNode(OP_ASSIGN, createIdentifierLeaf(@ID.name@, getKindOfName(@Stat.0.out@, @ID.name@), getParameterIndex(@Stat.0.out@, @ID.name@), getKindOfName(@Stat.0.out@, @ID.name@) == KIND_VARIABLE ? getLocalVarOffset(@Stat.0.out@, @ID.name@) : getClassVarOffset(@Stat.0.out@, @ID.name@)), @Expr.0.tree@);
                    @reg {
                        @Stat.0.tree@->regStor = getFirstRegister(); 
                        @Expr.0.tree@->regStor = @Stat.0.tree@->regStor;
                    }
                @}
                | Expr /* Ausdrucksanweisung */
                @{
                    @i @Expr.0.ids@ = @Stat.0.in@ ;
                    @i @Stat.0.out@ = @Stat.0.in@ ;

                    @i @Stat.0.condCounterOut@ = @Stat.0.condCounterIn@;
                    @i @Expr.0.classList@ = @Stat.0.classList@;

                    @i @Stat.0.tree@ = NULL; /* not needed */
                @}
                ;

Return          : RETURN Expr 
                @{
                    @i @Expr.0.ids@ = @Return.0.in@;
                    @i @Expr.0.classList@ = @Return.0.classList@;
                    
                    @typeCheck checkForEqualType(@Return.0.type@, @Expr.0.type@);

                    @i @Return.0.tree@ = createNode(OP_RETURN, @Expr.0.tree@, NULL);
                    @reg {
                        @Return.0.tree@->regStor = getFirstRegister(); 
                        @Expr.0.tree@->regStor = @Return.0.tree@->regStor;
                    }
                @}
                ;

Conditions      : COND StartGuarded END
                @{
                    @i @StartGuarded.0.in@ = @Conditions.0.in@;
                    @i @StartGuarded.0.type@ = @Conditions.0.type@;
                    @i @StartGuarded.0.className@ = @Conditions.0.className@;
                    @i @StartGuarded.0.functionName@ = @Conditions.0.functionName@;
                    @i @StartGuarded.0.condCounterIn@ = @Conditions.0.condCounterIn@ + 1;
                    @i @StartGuarded.0.classList@ = @Conditions.0.classList@;

                    @i @Conditions.0.condCounterOut@ = @StartGuarded.0.condCounterOut@;
                    @i @Conditions.0.tree@ = NULL;
                    
                    /* Produce end label for cond */
                    @burm writeEndLabel(prepareLabelString("cond", @Conditions.0.className@, @Conditions.0.functionName@, @StartGuarded.0.condCounterIn@));
                @}
                ;

StartGuarded    : OptGuarded
                @{
                    @i @OptGuarded.0.in@ = @StartGuarded.0.in@;
                    @i @OptGuarded.0.type@ = @StartGuarded.0.type@;
                    @i @OptGuarded.0.className@ = @StartGuarded.0.className@;
                    @i @OptGuarded.0.functionName@ = @StartGuarded.0.functionName@;
                    @i @OptGuarded.0.condCounterIn@ = @StartGuarded.0.condCounterIn@;
                    @i @OptGuarded.0.classList@ = @StartGuarded.0.classList@;

                    @i @StartGuarded.0.condCounterOut@ = @OptGuarded.0.condCounterOut@;
                    
                    /* Produce start label for cond */
                    @burm @revorder(1) writeLabel(prepareLabelString("cond", @OptGuarded.0.className@, @OptGuarded.0.functionName@, @StartGuarded.0.condCounterIn@));
                @}
                ;

OptGuarded      : 
                @{
                    @i @OptGuarded.0.condCounterOut@ = @OptGuarded.0.condCounterIn@;
                @}
	            | OptGuarded Guarded ';'
                @{
                    @i @OptGuarded.1.in@ = @OptGuarded.0.in@;
                    @i @OptGuarded.1.condCounterIn@ = @OptGuarded.0.condCounterIn@;
                    @i @OptGuarded.1.type@ = @OptGuarded.0.type@;
                    @i @OptGuarded.1.classList@ = @OptGuarded.0.classList@;
                    @i @OptGuarded.1.className@ = @OptGuarded.0.className@;
                    @i @OptGuarded.1.functionName@ = @OptGuarded.0.functionName@;

                    @i @Guarded.0.in@ = @OptGuarded.0.in@;
                    @i @Guarded.0.type@ = @OptGuarded.0.type@;
                    @i @Guarded.0.condCounterIn@ = @OptGuarded.1.condCounterOut@;
                    @i @Guarded.0.classList@ = @OptGuarded.0.classList@;
                    @i @Guarded.0.className@ = @OptGuarded.0.className@;
                    @i @Guarded.0.functionName@ = @OptGuarded.0.functionName@;

                    @i @OptGuarded.0.condCounterOut@ = @Guarded.0.condCounterOut@;
                @}
	            ;

Guarded         : RIGHTASSIGN Stats BREAK 
                @{
                    @i @Stats.0.type@ = @Guarded.0.type@; 
                    @i @Stats.0.in@ = duplicate(@Guarded.0.in@);
                    @i @Stats.0.className@ = @Guarded.0.className@;
                    @i @Stats.0.functionName@ = @Guarded.0.functionName@;
                    @i @Stats.0.condCounterIn@ = @Guarded.0.condCounterIn@;
                    @i @Stats.0.classList@ = @Guarded.0.classList@;
                    @i @Stats.0.injectionIn@ = NULL; /* not needed */

                    @i @Guarded.0.condCounterOut@ = @Stats.0.condCounterOut@;
                    @i @Guarded.0.tree@ = NULL;  /* not needed */

                    /* write jump-instruction to jump to end of cond */
                    @burm writeJumpToEnd(prepareLabelString("cond", @Guarded.0.className@, @Guarded.0.functionName@, @Stats.0.condCounterIn@));
                @}
                | RIGHTASSIGN Stats CONTINUE 
                @{
                    @i @Stats.0.type@ = @Guarded.0.type@; 
                    @i @Stats.0.in@ = duplicate(@Guarded.0.in@);
                    @i @Stats.0.className@ = @Guarded.0.className@;
                    @i @Stats.0.functionName@ = @Guarded.0.functionName@;
                    @i @Stats.0.condCounterIn@ = @Guarded.0.condCounterIn@;
                    @i @Stats.0.classList@ = @Guarded.0.classList@;
                    @i @Stats.0.injectionIn@ = NULL;  /* not needed */

                    @i @Guarded.0.condCounterOut@ = @Stats.0.condCounterOut@;
                    @i @Guarded.0.tree@ = NULL;  /* not needed */

                    /* write jump-instruction to jump to the beginning of cond */
                    @burm writeJumpTo(prepareLabelString("cond", @Guarded.0.className@, @Guarded.0.functionName@, @Stats.0.condCounterIn@));
                @}
                | Expr RIGHTASSIGN Stats BREAK 
                @{
                    @i @Expr.0.ids@ = @Guarded.0.in@;
                    @i @Expr.0.classList@ = @Guarded.0.classList@;

                    @typeCheck checkForEqualType(@Expr.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @Stats.0.type@ = @Guarded.0.type@; 
                    @i @Stats.0.in@ = duplicate(@Guarded.0.in@);
                    @i @Stats.0.className@ = @Guarded.0.className@;
                    @i @Stats.0.functionName@ = @Guarded.0.functionName@;
                    @i @Stats.0.condCounterIn@ = @Guarded.0.condCounterIn@;
                    @i @Stats.0.classList@ = @Guarded.0.classList@;
                    @i @Stats.0.injectionIn@ = @Guarded.0.tree@;

                    @i @Guarded.0.condCounterOut@ = @Stats.0.condCounterOut@;
                    @i @Guarded.0.tree@ = createNode(OP_COND, createIfLabelLeaf(prepareLabelString("label", @Guarded.0.className@, @Guarded.0.functionName@, globalGuardCounter++)), @Expr.tree@);
                    @reg {
                        @Guarded.0.tree@->regStor = getFirstRegister(); 
                        @Expr.0.tree@->regStor = @Guarded.0.tree@->regStor;
                    }

                    /* write jump-instruction to jump to the end of cond */
                    @burm {
                        writeJumpToEnd(prepareLabelString("cond", @Guarded.0.className@, @Guarded.0.functionName@, @Stats.0.condCounterIn@));
                        writeEndLabel(@Guarded.0.tree@->kids[0]->identifierName);
                    }
                @}
                | Expr RIGHTASSIGN Stats CONTINUE 
                @{
                    @i @Expr.0.ids@ = @Guarded.0.in@ ;
                    @i @Expr.0.classList@ = @Guarded.0.classList@;
                    
                    @typeCheck checkForEqualType(@Expr.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @Stats.0.type@ = @Guarded.0.type@; 
                    @i @Stats.0.in@ = duplicate(@Guarded.0.in@);
                    @i @Stats.0.className@ = @Guarded.0.className@;
                    @i @Stats.0.functionName@ = @Guarded.0.functionName@;
                    @i @Stats.0.condCounterIn@ = @Guarded.0.condCounterIn@;
                    @i @Stats.0.classList@ = @Guarded.0.classList@;
                    @i @Stats.0.injectionIn@ = @Guarded.0.tree@;

                    @i @Guarded.0.condCounterOut@ = @Stats.0.condCounterOut@;
                    @i @Guarded.0.tree@ = createNode(OP_COND, createIfLabelLeaf(prepareLabelString("label", @Guarded.0.className@, @Guarded.0.functionName@, globalGuardCounter++)), @Expr.tree@);
                    @reg {
                        @Guarded.0.tree@->regStor = getFirstRegister(); 
                        @Expr.0.tree@->regStor = @Guarded.0.tree@->regStor;
                    }

                    /* write jump-instruction to jump to the beginning of cond */
                    @burm {
                        writeJumpTo(prepareLabelString("cond", @Guarded.0.className@, @Guarded.0.functionName@, @Stats.0.condCounterIn@ ));
                        writeEndLabel(@Guarded.0.tree@->kids[0]->identifierName);
                    }
                @}
                ;

Expr            : Negations
                @{
                    @i @Negations.0.ids@ = @Expr.0.ids@;
                    @i @Negations.0.classList@ = @Expr.0.classList@;
                    
                    @i @Expr.0.type@ = @Negations.0.type@;
                    @i @Expr.0.tree@ = @Negations.0.tree@; 

                    @reg @Negations.0.tree@->regStor = @Expr.0.tree@->regStor;   
                @}
                | Term PlusTerm
                @{
                    @i @Term.0.ids@ = @Expr.0.ids@;
                    @i @Term.0.classList@ = @Expr.0.classList@;
                    
                    @i @PlusTerm.0.ids@ = @Expr.0.ids@;
                    @i @PlusTerm.0.classList@ = @Expr.0.classList@;

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
                    @i @Term.0.classList@ = @Expr.0.classList@;

                    @i @MulTerm.0.ids@ = @Expr.0.ids@;
                    @i @MulTerm.0.classList@ = @Expr.0.classList@;

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
                    @i @Term.0.classList@ = @Expr.0.classList@;

                    @i @OrTerm.0.ids@ = @Expr.0.ids@;
                    @i @OrTerm.0.classList@ = @Expr.0.classList@;

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
                    @i @Term.0.classList@ = @Expr.0.classList@;

                    @i @Term.1.ids@ = @Expr.0.ids@;
                    @i @Term.1.classList@ = @Expr.0.classList@;

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
                    @i @Term.0.classList@ = @Expr.0.classList@;

                    @i @Term.1.ids@ = @Expr.0.ids@;
                    @i @Term.1.classList@ = @Expr.0.classList@;

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

                    @i @Expr.0.tree@ = createNewObjectLeaf(@ID.name@, countClassVarsForClass(@Expr.0.classList@, @ID.name@));
                    @reg @Expr.0.tree@->regStor = getFirstRegister();
                @}	
                ;

Negations       : Term
                @{
                    @i @Term.0.ids@ = @Negations.0.ids@;
                    @i @Term.0.classList@ = @Negations.0.classList@;

                    @i @Negations.0.type@ = @Term.0.type@;
                    @i @Negations.0.tree@ = @Term.0.tree@;
                    @reg @Term.0.tree@->regStor = @Negations.0.tree@->regStor;
                @}
                | NOT Negations
                @{
                    @i @Negations.1.ids@ = @Negations.0.ids@;
                    @i @Negations.1.classList@ = @Negations.0.classList@;
                    @i @Negations.0.type@ = @Negations.1.type@;
                    
                    @typeCheck checkForEqualType(@Negations.1.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @Negations.0.tree@ = createNode(OP_NOT, @Negations.1.tree@, NULL);
                    @reg @Negations.1.tree@->regStor = @Negations.0.tree@->regStor;
                @}
                | '-' Negations
                @{
                    @i @Negations.1.ids@ = @Negations.0.ids@;
                    @i @Negations.0.type@ = @Negations.1.type@;
                    @i @Negations.1.classList@ = @Negations.0.classList@;

                    @typeCheck checkForEqualType(@Negations.1.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @Negations.0.tree@ = createNode(OP_NEG, @Negations.1.tree@, NULL);
                    @reg @Negations.1.tree@->regStor = @Negations.0.tree@->regStor;
                @}
                ;

PlusTerm        : '+' Term 
                @{
                    @i @Term.0.ids@ = @PlusTerm.0.ids@;
                    @i @Term.0.classList@ = @PlusTerm.0.classList@;

                    @i @PlusTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    
                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @PlusTerm.0.tree@ = @Term.0.tree@ ; 
                    @reg @Term.0.tree@->regStor = @PlusTerm.0.tree@->regStor ;
                @}
	            | '+' Term PlusTerm
                @{
                    @i @PlusTerm.1.ids@ = @PlusTerm.0.ids@;
                    @i @PlusTerm.1.classList@ = @PlusTerm.0.classList@;
                    @i @PlusTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);

                    @i @Term.0.ids@ = @PlusTerm.0.ids@;
                    @i @Term.0.classList@ = @PlusTerm.0.classList@;

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
                    @i @Term.0.classList@ = @MulTerm.0.classList@;

                    @i @MulTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    
                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));    

                    @i @MulTerm.0.tree@ = @Term.0.tree@; 
                    @reg @Term.0.tree@->regStor = @MulTerm.0.tree@->regStor;                
                @}
                | '*' Term MulTerm
                @{
                    @i @MulTerm.1.ids@ = @MulTerm.0.ids@;
                    @i @MulTerm.1.classList@ = @MulTerm.0.classList@;
                    @i @MulTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);
                    
                    @i @Term.0.ids@ = @MulTerm.0.ids@;
                    @i @Term.0.classList@ = @MulTerm.0.classList@;

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
                    @i @Term.0.classList@ = @OrTerm.0.classList@;

                    @i @OrTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);

                    @typeCheck checkForEqualType(@Term.0.type@, newTypeWith(TYPE_INT, TYPE_NONE));

                    @i @OrTerm.0.tree@ = @Term.0.tree@; 
                    @reg @Term.0.tree@->regStor = @OrTerm.0.tree@->regStor;      
                @}
                | OR Term OrTerm
                @{
                    @i @OrTerm.1.ids@ = @OrTerm.0.ids@;
                    @i @OrTerm.1.classList@ = @OrTerm.0.classList@;
                    @i @OrTerm.0.type@ = newTypeWith(TYPE_INT, TYPE_NONE);

                    @i @Term.0.ids@ = @OrTerm.0.ids@;
                    @i @Term.0.classList@ = @OrTerm.0.classList@;
                    
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
                    @i @RepExpr.1.classList@ = @RepExpr.0.classList@;
   
                    @i @Expr.0.ids@ = @RepExpr.0.ids@;
                    @i @Expr.0.classList@ = @RepExpr.0.classList@;

                @}
                ;

Term            : '(' Expr ')'
                @{
                    @i @Expr.0.ids@ = @Term.0.ids@;
                    @i @Expr.0.classList@ = @Term.0.classList@;

                    @i @Term.0.type@ = @Expr.0.type@;
                    @i @Term.0.tree@ = @Expr.0.tree@;
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

                    @i @Term.0.tree@ = createIdentifierLeaf(@ID.name@, getKindOfName(@Term.ids@, @ID.name@), getParameterIndex(@Term.ids@, @ID.name@), getKindOfName(@Term.ids@, @ID.name@) == KIND_VARIABLE ? getLocalVarOffset(@Term.ids@, @ID.name@) : getClassVarOffset(@Term.ids@, @ID.name@));
                @}
                | ID '(' Expr RepExpr ')' /* Aufruf */
                @{
                    @i @Expr.0.ids@ = @Term.0.ids@;
                    @i @Expr.0.classList@ = @Term.0.classList@;

                    @i @RepExpr.0.ids@ = @Term.0.ids@;
                    @i @RepExpr.0.classList@ = @Term.0.classList@;
                    @i @RepExpr.0.type@ = newType();
                    
                    @i @Term.0.type@ = getType(@Term.0.ids@, @ID.name@, @ID.lineNr@);
                    
                    @visibilityCheck isVisible(@Term.0.ids@, @ID.name@, KIND_SELECTOR, @ID.lineNr@);

                    @i @Term.0.tree@ = NULL; /* not needed */
                @}
                ;

%%



int main(void)
{
    int ret = yyparse();
    return ret;
}

