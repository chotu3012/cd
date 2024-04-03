%{
#include <stdio.h>
int con = 0,vow = 0;
%}
%%
[aeiouAEIOU] {vow++;}
[a-zA-Z] {con++;}
%%
int yywrap()
{

}
void main()
{
  yylex();
  printf("No.of Vowels : %d\n",vow);
  printf("No.of Consonants : %d\n",con);
}
