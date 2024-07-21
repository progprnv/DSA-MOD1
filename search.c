
#include <stdio.h>

void search(int a[], int n, int x);

void main() {
    int a[20], n, x, i;

    printf("Enter size of array\n");
    scanf("%d", &n);

    printf("Enter elements of array\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Entered array is\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    search(a, n, x);
}

void search(int a[], int n, int x) {
    int i, flag = 0, pos;

    printf("Enter element to be searched\n");
    scanf("%d", &x);

    for (i = 0; i < n; i++) {
        if (a[i] == x) {
            flag = 1;
            pos = i + 1;
            printf("The element is in position %d\n", pos);
            break;
        }
    }

    if (flag == 0)
        printf("\nNo element found");
}
