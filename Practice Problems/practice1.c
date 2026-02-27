#include <stdio.h>

int main() {
    int n, x, f = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int ar[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &ar[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (ar[i] == x) {
            printf("Found using Linear Search\n");
            f = 1;
            break;
        }
    }
    int l = 0, h = n - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (ar[m] == x) {
            printf("Found using Binary Search\n");
            f = 1;
            break;
        } else if (ar[m] < x) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    if (f == 0) {
        printf("Number not found\n");
    }

    return 0;
}