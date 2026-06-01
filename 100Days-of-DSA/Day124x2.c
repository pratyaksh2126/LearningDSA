#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if(front == -1)
            front = 0;
        queue[++rear] = x;
        printf("%d inserted\n", x);
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
        printf("%d deleted\n", queue[front++]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    return 0;
}