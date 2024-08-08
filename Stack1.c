#include <stdio.h>

void insert(int a[], int n, int pos, int elem);
void delete(int a[], int n, int pos);
void search(int a[], int n, int x);
void traverse(int a[], int n);
void merge(int a[], int b[], int n, int m, int result[]);

int main() {
    int a[20], b[20], result[40], n, m, choice, x, pos, elem;

    printf("Enter size of array A: ");
    scanf("%d", &n);

    printf("Enter elements of array A: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    do {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Traverse\n");
        printf("5. Merge\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                insert(a, n, pos, elem);
                n++;  // Increase the size of the array
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(a, n, pos);
                n--;  // Decrease the size of the array
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &x);
                search(a, n, x);
                break;
            case 4:
                traverse(a, n);
                break;
            case 5:
                printf("Enter size of array B: ");
                scanf("%d", &m);
                printf("Enter elements of array B: ");
                for (int i = 0; i < m; i++) {
                    scanf("%d", &b[i]);
                }
                merge(a, b, n, m, result);
                printf("Merged array is: ");
                for (int i = 0; i < n + m; i++) {
                    printf("%d ", result[i]);
                }
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}

void insert(int a[], int n, int pos, int elem) {
    if (pos > n + 1 || pos <= 0) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos - 1] = elem;
}

void delete(int a[], int n, int pos) {
    if (pos > n || pos <= 0) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
}

void search(int a[], int n, int x) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("Element found at position %d\n", i + 1);
            flag = 1;
            break;
        }
    }
    if (!flag) {
        printf("Element not found\n");
    }
}

void traverse(int a[], int n) {
    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[], int b[], int n, int m, int result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        result[n + i] = b[i];
    }
}
