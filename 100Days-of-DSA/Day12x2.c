#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums1[1000], nums2[1000];
    int size1, size2;

    scanf("%d", &size1);

    for (int i = 0; i < size1; i++) {
        scanf("%d", &nums1[i]);
    }

    scanf("%d", &size2);

    for (int i = 0; i < size2; i++) {
        scanf("%d", &nums2[i]);
    }

    int freq[1001] = {0};

    for (int i = 0; i < size1; i++) {
        freq[nums1[i]]++;
    }

    printf("Intersection: ");

    for (int i = 0; i < size2; i++) {
        if (freq[nums2[i]] > 0) {
            printf("%d ", nums2[i]);
            freq[nums2[i]]--;
        }
    }

    return 0;
}
