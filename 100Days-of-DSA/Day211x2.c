#include <stdio.h>

int main() {
    int n, i, key, pos = -1;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            pos = i;
            break;
        }
    }

    if(pos != -1)
        printf("Found at index %d", pos);
    else
        printf("Not found");

    return 0;
}