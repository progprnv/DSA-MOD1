#include <stdio.h>
void search(int a[],int n,int x);
int void()
{
	int a[20],n,x,i;
	printf("enter the size of elements");
	scanf("%d", &n);
	
	printf("enter elements of array:");
	for(i=0;i<n;i++)
	{
	 scanf("%d",&a[i]); 
 }
 
 print("entered array;");
 for(i=0;i<n;i++)
 { printf("%d \n",&a[i]);
 }
 
 search(a,n,x);
}

void search(int a[],int n,int x)
{
	int i,flag=0;pos;
	
	printf("enter element to be searched \n");
	scanf("%d",&x);
	
	{ if(a[i]==x)
		{
			flag=1;
			pos=i+1;
			printf("the element is in position %d \n",pos);
			break;
		}
	}
	if (flag==0) {
		printf("element not found");
	}
}
