#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int value;
	struct Node *link;
};
typedef struct Node node1;
node1 *front = NULL, *rear = NULL;
void insert() 
{
	int val;
	node1 *nptr;
	nptr = (node1 *)malloc(sizeof(node1));
	if (nptr == NULL) 
	{
		printf("\nMemory allocation failed!\n");
		return;
	}
	printf("Enter the value to be inserted:");
	scanf("%d",&val);
	nptr->value = val;
	nptr->link = NULL;
	if (front == NULL) 
	{
		front = rear = nptr;
	} 
	else 
	{
		rear->link = nptr;
		rear = nptr;
	}
	printf("Insertion is Successful!!!\n");
}
void delete() 
{
	if (front == NULL) 
	{
		printf("\nQueue is Empty!!!\n");
	} 
	else 
	{
		node1 *temp = front;
		front = front->link;
		printf("Deleted element: %d\n", temp->value);
		free(temp);
		if (front == NULL) 
		{
			rear = NULL;
		}
	}
}
void display() 
{
	if (front == NULL) 
		printf("\nQueue is Empty!!!\n");	 
	else 
	{
		node1 *temp = front;
		printf("Queue elements: ");
		while (temp != NULL) 
		{
			printf("%d --->", temp->value);
			temp = temp->link;
		}
		printf("Null\n");
	}
}
void main()
{
	int ch;
	printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	while (1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert();break;
			case 2: delete(); break;
			case 3: display(); break;
			case 4: exit(0);break;
		}
	}
}

