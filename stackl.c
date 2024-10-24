#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int value;
	struct Node *link;
};
typedef struct Node node1;
node1 *top = NULL;
void push()
{
	node1 *nptr = (node1*)malloc(sizeof(node1));
	if (nptr == NULL)
	{
		printf("Memory Overflow\n");
		return;
	}
	int val;
	printf("Enter the value to be inserted:");
	scanf("%d",&val);
	nptr->value = val;
	nptr->link = top;
	top = nptr;
	printf("Insertion Successful!");
}
void pop()
{
	if (top == NULL)
	{
		printf("\nStack is Empty!\n");
	}
	else
	{
		node1 *temp = top;
		printf("\nDeleted element: %d", temp->value);
		top = top->link;
		free(temp);
	}
}
void display()
{
	if (top == NULL)
	{
		printf("\nStack is Empty!\n");
	}
	else
	{
		node1 *temp = top;
		printf("\nStack elements are:\n");
		while (temp != NULL) 
		{
			printf("%d ", temp->value);
			temp = temp->link;
		}
	
	}
}
void main()
{
	int ch;
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
	while (1)
	{	
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: exit(0);break;
		}
	}
}

