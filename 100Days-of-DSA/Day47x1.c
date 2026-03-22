#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isQueueEmpty() {
    return front > rear;
}

int isStackEmpty() {
    return top == -1;
}

int main() {
    int n, x;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    while(!isQueueEmpty()) {
        push(dequeue());
    }

    while(!isStackEmpty()) {
        enqueue(pop());
    }

    while(front <= rear) {
        printf("%d ", queue[front++]);
    }

    return 0;
}