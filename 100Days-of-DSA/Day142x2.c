#include <stdio.h>

int main()
{
    int n, i, key;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int low = 0, high = n - 1, mid, found = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            found = 1;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found)
        printf("Element found at index %d", mid);
    else
        printf("Element not found");

    return 0;
}