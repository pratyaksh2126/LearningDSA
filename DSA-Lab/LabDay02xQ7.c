// Linear Search using Dynamic memory allocation:- 

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, key, i;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

     printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d", i + 1);
            free(arr);
            return 0;
        }
    }

    printf("Element not found");

    Free(arr);

    return 0;
}
