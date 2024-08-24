24-08-24

Here's an example of a menu-driven program in C that performs binary and linear searches:

```
#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Key not found
}

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[100], n, choice, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in ascending order: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Binary Search\n");
        printf("2. Linear Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int result = binarySearch(arr, n, key);
                if (result != -1) {
                    printf("Key found at index %d\n", result);
                } else {
                    printf("Key not found\n");
                }
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = linearSearch(arr, n, key);
                if (result != -1) {
                    printf("Key found at index %d\n", result);
                } else {
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
```

This program first asks the user to enter the number of elements and the elements themselves in ascending order. Then, it presents a menu to the user to choose between binary search, linear search, or exit. Based on the user's choice, the program performs the corresponding search operation and displays the result.







19-08

```
#include <stdio.h>
#include <stdlib.h>

int rear = -1, front = 0, n;
struct element {
    int value, priority;
};
struct element pq[100], temp;

void enqueue() {
    if (rear >= n - 1) {
        printf("Queue is full\n");
    } else {
        rear = rear + 1;
        printf("Enter value and priority value to be inserted: ");
        scanf("%d %d", &pq[rear].value, &pq[rear].priority);
    }
}

void dequeue() {
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted element is %d\n", pq[front].value);
        front = front + 1;
    }
}

void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (pq[i].priority > pq[j].priority) {
                temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
        }
    }
}

int main() {
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    int choice;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Sort\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                sort();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
```
    
    
    
    
    
    
    
    
    
    
    
    



$$$$$End


##priority queue 

#include<stdio.h>
#include<stdlib.h>

int rear=-1, front=0, i, j, n;

struct element {
    int value, priority;
} pq[100], temp;

void sort() {
    for (i = front; i <= rear - 1; i++) {
        for (j = i + 1; j <= rear; j++) {
            if (pq[i].priority > pq[j].priority) {
                temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
        }
    }
}

void enqueue() {
    if (rear >= n - 1) {
        printf("The Queue is full\n");
    } else {
        rear = rear + 1;
        printf("Enter the value and its priority to be inserted: ");
        scanf("%d %d", &pq[rear].value, &pq[rear].priority);
        sort();
    }
}

void dequeue() {
    if (front > rear) {
        printf("The Queue is empty\n");
    } else {
        printf("The deleted element is %d \t", pq[front].value);
        front = front + 1;
    }
}

void display() {
    if (front > rear) {
        printf("The Queue is empty\n");
    } else {
        for (i = front; i <= rear; i++) {
            printf("%d \t", pq[i].value);
        }
        printf("\n");
    }
}

void main() {
    int choice;
    printf("Enter the size of the queue\t");
    scanf("%d", &n);
   
        while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice\t");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0); break;
            default: printf("Invalid choice\n");
        }
    }
}



******

##normal queue 

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = element;
        printf("Element enqueued successfully\n");
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front = front + 1;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;
    
    do {
        printf("Queue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}



****




ere is the algorithm and C code for a circular queue:

Algorithm
Initialize Variables

MAX_SIZE as the maximum size of the queue
queue as an array of size MAX_SIZE
front as -1
rear as -1
Enqueue Operation

If (rear + 1) % MAX_SIZE == front, print "Queue is full"
Else, if front == -1, set front = 0
Set rear = (rear + 1) % MAX_SIZE
Set queue[rear] = element
Print "Element enqueued successfully"
Dequeue Operation

If front == -1, print "Queue is empty"
Else, print "Dequeued element: queue[front]"
If front == rear, set front = -1 and rear = -1 (queue is now empty)
Else, set front = (front + 1) % MAX_SIZE
Display Operation

If front == -1, print "Queue is empty"
Else, iterate from front to rear using (i % MAX_SIZE) and print queue[i]
Main Function

Declare choice and element as integers
Use a do-while loop to display a menu and perform enqueue, dequeue, and display operations based on user input until the user chooses to exit.



#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
        printf("Element enqueued successfully\n");
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    int choice, element;
    
    do {
        printf("Queue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
