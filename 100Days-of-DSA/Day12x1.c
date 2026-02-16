#include <stdio.h>
#include <stdlib.h>

// Safe comparator for qsort (avoids overflow)
int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int nums1[1000], nums2[1000];
    int size1, size2;

    // Read size of first array
    scanf("%d", &size1);

    // Read elements of first array
    for (int i = 0; i < size1; i++) {
        scanf("%d", &nums1[i]);
    }

    // Read size of second array
    scanf("%d", &size2);

    // Read elements of second array
    for (int i = 0; i < size2; i++) {
        scanf("%d", &nums2[i]);
    }

    // Sort both arrays
    qsort(nums1, size1, sizeof(int), compare);
    qsort(nums2, size2, sizeof(int), compare);

    int i = 0, j = 0;

    // Two-pointer traversal
    while (i < size1 && j < size2) {
        if (nums1[i] < nums2[j]) {
            i++;
        } 
        else if (nums1[i] > nums2[j]) {
            j++;
        } 
        else {
            printf("%d ", nums1[i]);
            i++;
            j++;
        }
    }

    return 0;
}
