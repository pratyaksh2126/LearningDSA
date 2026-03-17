#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int heap[MAX];
int size = 0;
int k;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(int i) {
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < size && heap[l] < heap[smallest])
            smallest = l;
        if (r < size && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

void insert(int val) {
    heap[size++] = val;
    heapifyUp(size - 1);
    if (size > k) {
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }
}

int main() {
    int n, val;

    scanf("%d", &k);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(val);
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        scanf("%d", &val);
        insert(val);
        printf("%d\n", heap[0]);
    }

    return 0;
}