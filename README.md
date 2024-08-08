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



*****

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
