#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int i, key = 30, found = 0;

    for(i = 0; i < 5; i++) {
        if(arr[i] == key) {
            printf("Element found at index %d", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}