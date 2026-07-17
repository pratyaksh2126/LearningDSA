#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if(rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1)
        front = 0;

    queue[++rear] = value;
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);
    front++;
}

void display() {
    if(front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}