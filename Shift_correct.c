#include<stdio.h> 
#include<string.h> 
#include<ctype.h> 

struct Productions{
     char left[10];
     char right[10];
 };
 
 int main(){
   char temp[50],input[50],ch[2],stack[50],*token1,*token2,*substring;
   struct Productions rule[20];
   int n;
   printf("Enter number of productions: ");
   scanf("%d",&n);
   printf("Enter %d productins: in the form of (left->right)\n",n);
   for(int i=0;i<n;i++){
       scanf("%s",temp);
       token1=strtok(temp,"->");
       token2=strtok(NULL,"->");
       strcpy(rule[i].left,token1);
       strcpy(rule[i].right,token2);
   }
    printf("Enter input string: ");
    scanf("%s",input);
    int i=0;
    int l=strlen(input);
    
   while(1){
      if(i<l){
         ch[0]=input[i];
         ch[1]='\0';
         i++;
         //stack[0]='\0';
         strcpy(stack,ch);
         printf("%s\t",stack);
         for(int k=i;k<l;k++) 
           printf("%c",input[k]);
         printf("\t shift %s\n",ch);
         
      }
       int j;
       for(j=0;j<n;j++){
         substring=strstr(stack,rule[j].right);
         if(substring!=NULL){
          int sblen=strlen(substring);
          int stklen=strlen(stack);
          int top=stklen-sblen;
          stack[top]='\0';
          strcat(stack,rule[j].left);
          printf("%s\t",stack);
          for(int k=i;k<l;k++) 
           printf("%c",input[k]);
          printf("\t reduce %s->%s\n",rule[j].left,rule[j].right); 
          j=-1;
         }
       }
      if(strcmp(stack,rule[0].left)==0 && i==l){
          printf("String is accepted\n");
          
          break;
      } 
      if(i==l){
          printf("Error String is Regicted\n");
          
          break;
      }
   }
 }
