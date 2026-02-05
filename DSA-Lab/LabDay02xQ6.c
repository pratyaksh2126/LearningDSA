// Store 'n' numbers (integers or real) in an array. Conduct a linear search for a given number and report succes or failure in the form of a suitable message:-

#include <stdio.h>
int main()
{
    int n, i, key, found = 0;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

    printf("Enter elements to search: ");
    scanf("%d", &key);

    for (i = 0; i<n; i++)
    {
        if (arr[i] ==key)
        {
            found = 1;
            break;
        }
    }

    if (found)
    printf("Search Successful! Element found at position %d\n", i+1);
    else
    printf("Search Unsuccessful! Element not found\n");
    return 0;
}
