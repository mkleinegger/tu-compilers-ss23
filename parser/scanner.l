%{
#include <string.h>
#include <stdio.h>

#include "y.tab.h"

void removeOccurrencesOf(char *str, char charToRemove);
%}

DIGIT [0-9]
HEXDIGIT [0-9a-fA-F]
LETTER [a-zA-Z]

%x comment
%%
"(*" BEGIN(comment);
<comment>[\n\t ] ;
<comment>. ;
<comment>"*)" BEGIN INITIAL;

  /* Keyword rule */
"object"   return OBJECT;
"int"      return INT;
"class"    return CLASS;
"end"      return END;
"return"   return RETURN;
"cond"     return COND;
"continue" return CONTINUE;
"break"    return BREAK;
"not"      return NOT;
"or"       return OR;
"new"      return NEW;
"null"     return NULLTERM;

  /* Other lexamas rule */
";"   return yytext[0];
"("   return yytext[0];
","   return yytext[0];
")"   return yytext[0];
"<-"  return LEFTASSIGN;
"->"  return RIGHTASSIGN;
"-"   return yytext[0];
"+"   return yytext[0];
"*"   return yytext[0];
">"   return yytext[0];
"#"   return yytext[0];

  /* Identiefers rule */
{LETTER}({LETTER}|{DIGIT}|"_")* {
  yylval.id = strdup(yytext); 
  return ID;
}

  /* Decimal-numbers rule */
{DIGIT}({DIGIT}|"_")* {
  removeOccurrencesOf(yytext, '_');
  yylval.number =  strtoull(yytext, NULL, 10);
  return NUM;
}

  /* Hexadecimal-numbers rule */
"0x"(({HEXDIGIT}|"_")*{HEXDIGIT}({HEXDIGIT}|"_")*) {
  removeOccurrencesOf(yytext, '_');
  yylval.number = strtoull(yytext, NULL, 16);
  return NUM;
}

[\n|\t| ]+ ;	/* eat up whitespaces */

  /* Error rule */
. {
  printf("Error: Unrecognized character(s): %s\n", yytext);
  exit(1);
}
%%

int yywrap(void)
{
  return 1;
}

void yyerror (char const *message)
{

    fprintf(stderr, "Error parsing line: %s\n",  message);
    exit(2);
}

void removeOccurrencesOf(char* str, char charToRemove) {
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

