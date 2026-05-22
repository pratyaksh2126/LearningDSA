#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int key = 30;
    int size = 5;

    int result = binarySearch(arr, size, key);

    if(result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", result);

    return 0;
}