%top {
#include <string.h>
#include <stdlib.h>

void removeOccurrencesOf(char *str, char charToRemove);
}

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
"object"|"int"|"class"|"end"|"return"|"cond"|"continue"|"break"|"not"|"or"|"new"|"null" {
  printf("%s\n", yytext);
}

  /* Other lexamas rule */
";"|"("|","|")"|"<-"|"->"|"-"|"+"|"*"|">"|"#" {
  printf("%s\n", yytext);
}

  /* Identiefers rule */
{LETTER}({LETTER}|{DIGIT}|"_")* {
  printf("id %s\n", yytext);
}

  /* Decimal-numbers rule */
{DIGIT}({DIGIT}|"_")* {
  removeOccurrencesOf(yytext, '_');
  printf("num %lu\n", strtoull(yytext, NULL, 10));
}

  /* Hexadecimal-numbers rule */
"0x"(({HEXDIGIT}|"_")*{HEXDIGIT}({HEXDIGIT}|"_")*) {
  removeOccurrencesOf(yytext, '_');
  printf("num %lu\n", strtoull(yytext, NULL, 16));
}

[\n|\t| ]+ ;	/* eat up whitespaces */

  /* Error rule */
. {
  printf("Error: Unrecognized character: %s\n", yytext);
  exit(1);
}
%%

int yywrap(void)
{
  return 1;
}

int main() {
  yylex();
  exit(0);
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
