# 1 Linear Search and binary Search
 ```
 #include <stdio.h>
#define MAX_SIZE 20

int a[MAX_SIZE],i,n,low=0,high,mid,key;

int linear_search(int arr[],int size,int key)
       {
         for (int i=0;i<size;i++)
         {
           if(arr[i]==key)
           {
             return i;
           }
         }
         return -1;
       }
       
  int binary_search(int arr[],int size,int key) {
    
    int low=0;high = size -1,mid;
    
    while(low<=high) {
      mid=(low+high)/2;
      if(key<arr[mid])
      high=mid-1;
      else if(key>arr[mid])
      low=mid+1;
      else 
      return mid;
    }
    return -1;
  }
      
      
      int main()
      {
        int choice;
        
        printf("enter the size of array: \n");
        scanf("%d",&n);
        
        printf("enter elements in ascending order: ");
        for(i=0;i<n;i++)
        {
          scanf("%d",&a[i]);
        }
        
        printf("\n MENU\n");
        while(1)
          {
            printf("enter your choice:\n");
            printf("1.Linear Search");
            printf("2.Binary Search");
            printf("3.Exit\n");
            scanf("%d",&choice);
            
            if(choice ==3) {break;}
            
            
            
            printf("enter the element to search: ");
            scanf("%d",&key);
            
            int result;
            if(choice==1)
            {
              result=linear_search(a,n,key);
            }
            else if (choice==2)
            
            {
              result=binary_search(a,n,key);
            }
            
            if(result!=-1)
            printf("%d found at index %d",key,result);
            else
            printf("%d not found",key);
          }
      }
  ```

# 2 Infix to Postfix
            
          
        
      
