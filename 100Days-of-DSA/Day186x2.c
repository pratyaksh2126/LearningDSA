#include <stdio.h>

int main() {
    int arr[100], n, key, i, found = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Found at position %d", i + 1);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Not Found");

    return 0;
}