%{
#include <stdio.h>
int newline = 0,space = 0,tab = 0,ch = 0;
%}
%%
[\n] {newline++;space++;}
[\t] {tab++;space++;}
[ ] {space++;}
. {ch++;}
%%
int yywrap()
{
}
void main()
{
 yylex();
 printf("Enter No.of newlines : %d\n",newline);
 printf("Enter No.of tabs : %d\n",tab);
 printf("Enter No.of words : %d\n",space);
 printf("Enter No.of characters : %d\n",ch);
 
}
