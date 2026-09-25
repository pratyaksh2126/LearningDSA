#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int key, i, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < 5; i++) {
        if(arr[i] == key) {
            printf("Element found at position %d", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}