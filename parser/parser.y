%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char const*);

extern int yylex();

%}

%locations

%union { unsigned long number; char* id; }

%token OBJECT INT CLASS END RETURN COND CONTINUE BREAK NOT OR NEW NULLTERM
%token LEFTASSIGN RIGHTASSIGN

%token <id> ID
%token <number> NUM

%start Program

%%
Program: 
       | Program Selector ';'
       | Program Class ';'
       ;

Selector: Type ID '(' OptType ')'
        ;

OptType: OBJECT
       | OptType ',' Type
       ;

Type: INT
    | OBJECT
    ;

Class: CLASS ID /* Klassendefinition */
         OptMember
       END
     ;

OptMember:
	 | OptMember Member ';'
    	 ;

Member: Type ID/* Objektvariablendefinition */
      | Type ID '(' Pars ')' Stats Return END /* Methodenimplementierung */
      ;

Pars: Par
    | Pars ',' Par
    ;

Par: Type ID  /* Parameterdefinition */
   ;

Stats: 
     | Stats Stat ';'
     ;

Stat: Return
    | Cond
    | Type ID LEFTASSIGN Expr /* Variablendefinition */
    | ID LEFTASSIGN Expr /* Zuweisung */
    | Expr         /* Ausdrucksanweisung */
    ;

Return: RETURN Expr
      ;

Cond: COND OptGuarded END
      ;

OptGuarded:
	  | OptGuarded Guarded ';'
	  ;

Guarded: OptExpr RIGHTASSIGN Stats CONTINUE
       | OptExpr RIGHTASSIGN Stats BREAK
       ;

Expr: NotMinus
    | Term PlusTerm
    | Term MulTerm
    | Term OrTerm
    | Term '#' Term
    | Term  '>' Term
    | NEW ID
    ;

OptExpr:
       | Expr
       ;

NotMinus: NOT NotMinus
	| '-' NotMinus
	| Term
	;

PlusTerm: '+' Term 
	| PlusTerm '+' Term
	;

MulTerm: '*' Term
       | MulTerm '*' Term
       ;

OrTerm: OR Term
      | OrTerm OR Term
      ;

RepExpr:
       | RepExpr ',' Expr
       ;

Term: '(' Expr ')'
    | NUM
    | NULLTERM
    | ID /* lesender Zugriff */
    | ID '(' Expr RepExpr ')' /* Aufruf */
    ;

%%

int main(void)
{
    int ret = yyparse();
    return ret;
}

