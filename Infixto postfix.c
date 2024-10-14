
#include <stdio.h>
#include <ctype.h>
#define MAX 20
char postfix[MAX];
int top = -1;
void push(char x) 
{
  if (top < MAX - 1) 
  {
   top = top + 1;
   postfix[top] = x;
  }
}
char pop() 
{
  if (top == -1) 
  {
    return -1;
  }
  else 
   {
    return postfix[top--];
   }
}
int priority(char x)
 {
   if (x == '(') return 0;
   if (x == '+' || x == '-') return 1;
   if (x == '*' || x == '/') return 2;
   if (x == '^') return 3;
   return -1;
 }
 int main()
{
 char infix[MAX], *e, x;
 printf("Enter the expression: ");
 scanf("%s", infix);
 e = infix;
 while (*e != '\0')
  {
    if (isalnum(*e))
     {
       printf("%c", *e);
     } 
      else if (*e == '(')
       {
        push(*e);
       } 
        else if (*e == ')')
         {
          while ((x = pop()) != '(')  
          {
           if (x == -1) break;
           printf("%c", x);
          }
         } 
           else
            {
             while (top != -1 && priority(postfix[top]) >= priority(*e))
              {
               printf("%c", pop());
              }
              push(*e);
           }
            e++;
  }
   while (top != -1)
    {
      printf("%c", pop());
    }
    return 0;
}
