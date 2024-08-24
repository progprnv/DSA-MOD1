#include <stdio.h>

int binarysearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1; // Key not found
}

int linearsearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1; // Key not found
}

int main()
{
    int arr[100], n, choice, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in ascending order: \n", n);
  
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
  
    while (1)
    {
        printf("\n--MENU--\n");
        printf("1. Binary Search\n2. Linear Search\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
  
        switch (choice)
        {
            case 1: 
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int result = binarysearch(arr, n, key);
                if (result != -1)
                {
                    printf("Key found at index %d\n", result);
                }
                else
                {
                    printf("Key not found\n");
                }
                break;
                
            case 2: 
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = linearsearch(arr, n, key);
                if (result != -1)
                {
                    printf("Key found at index %d\n", result);
                }
                else
                {
                    printf("Key not found\n");
                }
                break;
                
            case 3: 
                return 0;
                
            default: 
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}
