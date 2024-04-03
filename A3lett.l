%{
#include <stdio.h>
int count = 0,len = 0;
void fun(int len);
%}
%%
[a-zA-Z0-9]+ {len = yyleng;fun(len);}
%%
void fun(int len)
{
 if(yytext[0] == 'A')
 {
   if(len == 3)
     printf("%s ",yytext);
 }
}
int yywrap()
{
  return 1;
}
void main()
{
  yylex();
}
