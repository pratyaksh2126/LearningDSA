#include <stdio.h>
#include <stdlib.h>

int compareStart(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareEnd(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int* start, int* end, int n) {
    qsort(start, n, sizeof(int), compareStart);
    qsort(end, n, sizeof(int), compareEnd);

    int i = 0, j = 0, rooms = 0, maxRooms = 0;

    while (i < n && j < n) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main() {
    int n;
    scanf("%d", &n);

    int start[n], end[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &start[i], &end[i]);

    printf("%d\n", minMeetingRooms(start, end, n));

    return 0;
}