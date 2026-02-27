#include <stdio.h>
#include <stdlib.h>

void duplicate(int arr[], int n) {
    int i, j;
    int found = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("Duplicate of %d found at indices %d and %d\n", arr[i], i, j);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("No duplicates found.\n");
    }
}

int main() {
    int n;
    printf("Enter the array length: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
    duplicate(arr, n);
    return 0;
}