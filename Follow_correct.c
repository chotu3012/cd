#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[10][10],result[20];
int n,m;
void follow(char);

void AddResult(char c)
{
  for(int k=0;k<=m;k++)
  {
    if(result[k]==c)
    return;
    
  }
  result[m++]=c;
}

void first(char c)
{
   if(!isupper(c)){
    AddResult(c);
   // return;
    }
   for(int k=0;k<n;k++)
   {
     if(a[k][0]==c){
       if(a[k][2]=='$') follow(a[k][0]);
       else if(islower(a[k][2]))
         AddResult(a[k][2]);
        else
          first(a[k][2]);
     }
   }
}

void follow(char c)
{
  if(a[0][0]==c) AddResult('$');
  for(int i=0;i<n;i++){
    for(int j=2;j<strlen(a[i]);j++)
    {
       if(a[i][j]==c)
       {
       if(a[i][j+1]!='\0') first(a[i][j+1]);
       if(a[i][j+1]=='\0') follow(a[i][0]);
          
       }
    }
  }
}


void main(){
int i,d;
char c;
   printf("enter the number of productions:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
     printf("enter the production %d:",i+1);
     scanf("%s",a[i]);
   }
  do{
  m=0;
   printf("find follow of:");
   scanf(" %c",&c);
   follow(c);
   printf("FOLLOW(%c):{",c);
   for(i=0;i<m;i++)
     printf("%c ",result[i]);
   printf(" }\n");
   printf("enter 1 to continue:");
   scanf("%d",&d);
  }
  while(d==1);
}
