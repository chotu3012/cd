#include<stdio.h>
#include<ctype.h>
int numOfProductions;
char productionSet[10][10];


void AddToResult(char result[],char c)
{
 int k;
   for(k=0;result[k]!='\0';k++)
     if(result[k]==c)
        return;
    result[k]=c;
    result[k+1]='\0';
}




void First(char* result,char c)
{
  int i,j,foundEpsilon,k;
  char subResult[20];
  subResult[0]='\0';
  result[0]='\0';
  if(!isupper(c)){
     AddToResult(result,c);
     return;
  }
  for(i=0;i<numOfProductions;i++)
  {
      if(productionSet[i][0]==c)
      {
         if(productionSet[i][2]=='$')
            AddToResult(result,'$');
            
         else
         {
           j=2;
           while(productionSet[i][j]!='\0'){
               foundEpsilon=0;
               First(subResult,productionSet[i][j]);
               for(k=0;subResult[k]!='\0';k++)
                  AddToResult(result,subResult[k]);
               for(k=0;subResult[k]!='\0';k++){
                  if(subResult[k]=='$')
                  {
                     foundEpsilon=1;
                     break;
                  }
                  
               }
               if(!foundEpsilon)
                    break;
                j++;
           }
         }
      }
  }
  return;
}


void main(){
  int i;
  char c,result[20],choice;
  printf("enter the number of productions:");
  scanf("%d",&numOfProductions);
  for(i=0;i<numOfProductions;i++)
  {
     printf("enter the production %d:",i+1);
     scanf("%s",productionSet[i]);
  }
  do{
	  printf("find the first of :");
	  scanf(" %c",&c);
	  First(result,c);
	  printf("FIRST(%c):{ ",c);
	  for(i=0;result[i]!='\0';i++)
	    printf(" %c",result[i]);
	    printf(" }\n");
	  printf("press 'y' to continue:");
	  scanf(" %c",&choice);
  
  }
  while(choice == 'y' || choice == 'Y');
  
}

