Room: scmsLink to this room
f has joined the room.
f:
#include <stdio.h> int stack[20],top=-1,n,x,i; void push(); void pop(); void display(); void peek(); int isEmpty(); int isFull(); int main() { int ch,wish; printf("enter size of element \n"); scanf("%d",&n); do { printf("\n --MENU-- \n"); printf("1.push 2. pop 3. display 4. peek \n"); printf("enter ur choice
j has joined the room.
f:
{ int ch,wish; printf("enter size of element \n"); scanf("%d",&n); do { printf("\n --MENU-- \n"); printf("1.push 2. pop 3. display 4. peek \n"); printf("enter ur choice"); scanf("%d",&ch); switch(ch) { case 1: push(); break; case 2: pop(); break; case 3: display(); break; case 4: peek(); break; } printf("do u wish to continue? \n"
f:
ith thett ann
f:
#include <stdio.h> int stack[20],top=-1,n,x,i; void push(); void pop(); void display(); void peek(); int isEmpty(); int isFull(); int main() { int ch,wish; printf("enter size of element \n"); scanf("%d",&n); do { printf("\n --MENU-- \n"); printf("1.push 2. pop 3. display 4. peek \n"); printf("enter ur choice"); scanf("%d",&ch); switch(ch) { case 1: push(); break; case 2: pop(); break; case 3: display(); break; case 4: peek(); break; } printf("do u wish to continue? \n"
f:
full ind
prnv has joined the room.
f:
printf("do u wish to continue? 1/0 \n"); scanf("%d",&wish); while (wish==1) ; } void push () { if(isFull()) printf("stack overflow"); } else { top++; { printf("enter element"); scanf("%d",&x); stack[top]=x; } } void pop() { if(isEmpty()) printf("stack underflow"); } else { printf("deleted element is %d",stack[top]); top--; } }
f:
#include <stdio.h> int stack[20],top=-1,n,x,i; void push(); void pop(); void display(); void peek(); int isEmpty(); int isFull(); int main() { int ch,wish; printf("enter size of element \n"); scanf("%d",&n); do { printf("\n --MENU-- \n"); printf("1.push 2. pop 3. display 4. peek \n enter ur choice"); scanf("%d",&ch); switch(ch) { case 1: push(); break; case 2: pop(); break; case 3: display(); break; case 4: peek(); break; } printf("do u wish to continue? 1/0 \n"); scanf("%d",&wish); while (wish==1) ; } void push () { if(isFull()) printf("stack overflow"); } else { top++; { printf("enter element"); scanf("%d",&x); stack[top]=x; } } void pop() { if(isEmpty()) printf("stack underflow"); } else { printf("deleted element is %d",stack[top]); top--; } } void display() { if(!isEmpty()) { printf("elements present in stack are :"); for(i=top;i>-1;i--) {printf("%d",sta
gvbd has joined the room.
j has joined the room.
gvbd:
void display() { if(!isEmpty()) { printf("elements present in stack are :"); for(i=top;i>-1;i--) {printf("%d",stack[i]);} } else { printf("%d",stack[i]); } } else { printf("\n stack empty"); } } void peek() { printf(" \n top=%d",stack[top]); } int isEmpty() { if(top<=-1) return(1); else return(0); } int isFull() { if(top>=n-1) return (1); else return (0); }
s has joined the room.
s:
coorec
s:
#include <stdio.h> int stack[20]; int top = -1; int n, x, i; void push(); void pop(); void display(); void peek(); int isEmpty(); int isFull(); int main() { int ch, wish; printf("Enter size of stack: "); scanf("%d", &n); do { printf("\n-- MENU --\n"); printf("1. Push\n2. Pop\n3. Display\n4. Peek\nEnter your choice: "); scanf("%d", &ch); switch (ch) { case 1: push(); break; case 2: pop(); break; case 3: display(); break; case 4: peek(); break; default: printf("Invalid choice!\n"); }
s:
printf("Do you wish to continue? (1/0): "); scanf("%d", &wish); } while (wish == 1); printf("Exiting the program.\n"); return 0; } void push() { if (isFull()) { printf("Stack overflow!\n"); } else { top++; printf("Enter element: "); scanf("%d", &x); stack[top] = x; } } void pop() { if (isEmpty()) { printf("Stack underflow!\n"); } else { printf("Deleted element is %d\n", stack[top]); top--; } } void display() { if (isEmpty()) { printf("Stack is empty.\n"); } else { printf("Elements present in stack are: "); for (i = top; i >= 0; i--) { printf("%d ", stack[i]); } printf("\n"); } }
s:
void peek() { if (isEmpty()) { printf("Stack is empty.\n"); } else { printf("Top element is %d\n", stack[top]); } } int isEmpty() { return (top <= -1); } int isFull() { return (top >= n - 1); }
gg has joined the room.
