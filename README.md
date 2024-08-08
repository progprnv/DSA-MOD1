priority queue 

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



