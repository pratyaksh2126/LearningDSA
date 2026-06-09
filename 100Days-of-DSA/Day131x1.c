#include <stdio.h>

int main() {
    int arr[100], n, key, i, found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Element found at position %d", i + 1);
    else
        printf("Element not found");

    return 0;
}