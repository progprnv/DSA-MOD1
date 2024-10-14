#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
# define max 15
 char infix[max],postfix[max];
 int stack[max];
 void itop();
 void push(char);
 char pop();
 int prec(char);
 void eval();
 int top=0;

void main()
{       
         printf("Enter infix expression ");
         scanf("%s",infix);
         itop();  //infix to postfix
         eval(); //postfix evaluation
  }

void itop()
{
     int i,p=0,precedence,len;
     char next;
     stack[top]='#';
     len=strlen(infix);
     infix[len]='#';
     for(i=0;infix[i]!='#';i++)
       {
           switch(infix[i])
           {
	           case '(': push(infix[i]);
	                     break;
	           case ')': while((next=pop())!='(')
		                	postfix[p++]=next;
			             break;
               case '+' :
	           case '-' :
	           case '*' :
               case '/' :
               case '%' :
               case '^' :
		                 precedence=prec(infix[i]);
		                 while(stack[top]!='#' && precedence<=prec(stack[top])) //in stack priority >= incoming priority
		                     postfix[p++]=pop();
		                     push(infix[i]);
		                     break;
	           default :     postfix[p++]=infix[i]; //operands

            }

    }
while(stack[top]!='#') //Remaining elements in stack
      postfix[p++]=pop();
      postfix[p]='\0';
      printf("%s",postfix);
  
}

int prec(char symbol)
{
  switch(symbol)
   {
	case '(': return 0;

	case '+' :
	case '-' : return 1;
	case '*' :
	case '/' :
	case '%' : return 2;
	case '^' : return 3;

   }
}
void push( char symbol)
{
  if(top>max)
  {
    printf("stack full");
    exit(0);
  }
  else
  {
   stack[++top]=symbol;
  }
}

char pop()
{
  if(top==-1)
  {
   printf("stack underflow");
   exit(0);
  }
  else
  {
   return(stack[top--]);
  }
}

void eval()
{
 int l,i,a,b,res;
 l=strlen(postfix);
 postfix[l]='#';
 for(i=0;postfix[i]!='#';i++)
 {
   if(postfix[i]<='9' && postfix[i]>='0')
   {
     push (postfix[i]-48);
   }
   else
   {
     a=pop();
     b=pop();
     switch(postfix[i])

     {
	case '+' : push(b+a); break;
	case '-' : push(b-a); break;
	case '*' : push(b*a); break;
	case '/' : push(b/a); break;
	case '%' : push(b%a); break;
	case '^' : push(pow(b,a)); break;


     }

   }
 }
 res=pop();
 printf("\n eval res : %d", res);
}
