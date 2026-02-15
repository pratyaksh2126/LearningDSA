#include <stdio.h>

int main() {
    int nums1[1000], nums2[1000];
    int size1, size2;

    printf("Enter size of nums1: ");
    scanf("%d", &size1);

    printf("Enter elements of nums1: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter size of nums2: ");
    scanf("%d", &size2);

    printf("Enter elements of nums2: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &nums2[i]);
    }

    int count[1001] = {0};

    for (int i = 0; i < size1; i++) {
        count[nums1[i]]++;
    }

    printf("Intersection: ");
    for (int i = 0; i < size2; i++) {
        if (count[nums2[i]] > 0) {
            printf("%d ", nums2[i]);
            count[nums2[i]]--; 
        }
    }

    printf("\n");

    return 0;
}
