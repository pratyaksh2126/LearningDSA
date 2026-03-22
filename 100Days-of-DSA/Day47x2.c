#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 50000

typedef struct {
    int maxHeap[HEAP_SIZE];
    int minHeap[HEAP_SIZE];
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapifyUp(int heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] >= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

void maxHeapifyDown(int heap[], int n, int i) {
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;
        if (l < n && heap[l] > heap[largest]) largest = l;
        if (r < n && heap[r] > heap[largest]) largest = r;
        if (largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}

void minHeapifyUp(int heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] <= heap[i]) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

void minHeapifyDown(int heap[], int n, int i) {
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < n && heap[l] < heap[smallest]) smallest = l;
        if (r < n && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

MedianFinder* create() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void addNum(MedianFinder* obj, int num) {
    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        obj->maxHeap[obj->maxSize++] = num;
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    } else {
        obj->minHeap[obj->minSize++] = num;
        minHeapifyUp(obj->minHeap, obj->minSize - 1);
    }

    if (obj->maxSize > obj->minSize + 1) {
        int val = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
        maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);
        obj->minHeap[obj->minSize++] = val;
        minHeapifyUp(obj->minHeap, obj->minSize - 1);
    } else if (obj->minSize > obj->maxSize) {
        int val = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);
        obj->maxHeap[obj->maxSize++] = val;
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    }
}

double findMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize) {
        return obj->maxHeap[0];
    } else {
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
    }
}

int main() {
    MedianFinder* obj = create();
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        addNum(obj, x);
        printf("%.1f\n", findMedian(obj));
    }

    free(obj);
    return 0;
}