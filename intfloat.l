%{
#include <stdio.h>
%}
%%
[0-9]+"."[0-9]+ {printf("Float ");}
[0-9]+ {printf("Integer ");}
%%
int yywrap()
{

}
void main()
{
  yylex();
}
