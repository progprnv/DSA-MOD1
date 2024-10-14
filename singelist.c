#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *link;
};

typedef struct node node1;

void in_beg();
void in_end();
void in_bw();
void del_beg();
void del_end();
void del_bw();
void display();
node1 *create();
node1 *start = NULL;

int main() {
    int ch, wish;

    do {
        printf("\n\n\tLinked List Implementation\n\t*****************************\n");
        printf("\t1. Insert at Beginning\n");
        printf("\t2. Insert at End\n");
        printf("\t3. Insert in Between\n");
        printf("\t4. Delete from Beginning\n");
        printf("\t5. Delete from End\n");
        printf("\t6. Delete in Between\n");
        printf("\t7. Display\n");
        printf("\t8. Exit\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: in_beg(); break;
            case 2: in_end(); break;
            case 3: in_bw(); break;
            case 4: del_beg(); break;
            case 5: del_end(); break;
            case 6: del_bw(); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("\nInvalid choice\n");
        }

        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d", &wish);

    } while(wish == 1);

    return 0;
}

node1 *create() {
    node1 *nptr = (node1*)malloc(sizeof(node1));
    if(nptr == NULL) {
        printf("Memory overflow\n");
        exit(1); // Exit if memory allocation fails
    }
    return nptr;
}

void in_beg() {
    int val;
    node1 *nptr = create();
    printf("Enter element: ");
    scanf("%d", &val);
    nptr->value = val;
    nptr->link = start;
    start = nptr;
}

void in_end() {
    node1 *temp, *nptr = create();
    int val;
    printf("Enter element: ");
    scanf("%d", &val);
    nptr->value = val;
    nptr->link = NULL;

    if (start == NULL) {
        start = nptr; // If list is empty
    } else {
        temp = start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = nptr;
    }
}

void in_bw() {
    node1 *temp, *nptr = create();
    int val, pos, i;
    printf("Enter element and position to be inserted: ");
    scanf("%d %d", &val, &pos);
    nptr->value = val;

    if (pos == 1) {
        nptr->link = start;
        start = nptr;
    } else {
        temp = start;
        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->link;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(nptr); // Free allocated memory
        } else {
            nptr->link = temp->link;
            temp->link = nptr;
        }
    }
}

void display() {
    node1 *temp = start;
    if (temp == NULL) {
        printf("LIST EMPTY!!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->link;
    }
    printf("\n");
}

void del_beg() {
    if (start == NULL) {
        printf("LIST EMPTY\n");
    } else {
        node1 *temp = start;
        start = start->link;
        free(temp);
    }
}

void del_end() {
    if (start == NULL) {
        printf("LIST EMPTY\n");
        return;
    }
    node1 *temp = start;
    node1 *prev = NULL;
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    if (prev == NULL) {
        // Only one node in the list
        start = NULL;
    } else {
        prev->link = NULL;
    }
    free(temp);
}

void del_bw() {
    int pos, i;
    printf("Enter position of the node to be deleted: ");
    scanf("%d", &pos);

    if (start == NULL || pos < 1) {
        printf("Invalid position or LIST EMPTY\n");
        return;
    }

    node1 *temp = start;
    node1 *prev = NULL;

    if (pos == 1) {
        start = start->link;
        free(temp);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
}
