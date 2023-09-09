%option yylineno
%option noyywrap

%top{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "type.h"
#include "code_generator.h"
#include "oxout.tab.h"

void removeOccurencesOf(char *str, char charToRemove);
}

%x COMMENT

DIGIT       [0-9]
HEX_DIGIT   [a-fA-F0-9]
LETTER      [a-zA-Z]

%%

    /* Comment rule */
"(*"            BEGIN(COMMENT);
<COMMENT>"*)"   BEGIN(INITIAL);
<COMMENT>\n
<COMMENT>.

    /* Keyword rule */
"object"        return OBJECT;
"int"           return INT;
"class"         return CLASS;
"end"           return END;
"return"        return RETURN;
"cond"          return COND;
"continue"      return CONTINUE;
"break"         return BREAK;
"not"           return NOT;
"or"            return OR;
"new"           return NEW;
"null"          return NULLTERM;

    /* Other lexemes rule */
";"             return ';';
"("             return '(';
","             return ',';
")"             return ')';
"-"             return '-';
"+"             return '+';
"*"             return '*';
">"             return '>';
"#"             return '#';
"<-"            return LEFTASSIGN;
"->"            return RIGHTASSIGN;

    /* Identifier rule */
{LETTER}({LETTER}|{DIGIT}|"_")* return ID; @{ @ID.name@ = strndup(yytext, yyleng + 1); @ID.lineNr@ = yylineno; @}

    /* Decimal numbers rule */
{DIGIT}({DIGIT}|"_")* return NUM; @{ removeOccurencesOf(yytext, '_'); @NUM.value@ = strtoul(yytext, NULL, 10); @}

    /* Hexadecimal numbers rule */
"0x"({HEX_DIGIT}|"_")*{HEX_DIGIT}({HEX_DIGIT}|"_")* return NUM; @{ removeOccurencesOf(yytext, '_'); @NUM.value@ = strtoul(yytext, NULL, 16); @}

    /* Whitespace rule */
[\t\n ]+

    /* Error rule */
. {
    fprintf(stderr, "Lexical error on line %d: %s\n", yylineno, yytext);
    exit(1);
}

%%


void yyerror(const char *err_msg)
{
    fprintf(stderr, "Parsing error on line %d: %s\n", yylineno, err_msg);
    exit(2);
}

void removeOccurencesOf(char *str, char charToRemove) {
    int i, j;
    int len = strlen(str);

    for(i=0; i<len; i++)
    {
        if(str[i] == charToRemove) 
        {
            for(j=i; j<len; j++) 
            {
                str[j] = str[j+1];
            }

            len--;
            i--;
        }
    }
}