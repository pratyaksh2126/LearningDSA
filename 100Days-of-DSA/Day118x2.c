#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if(rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("%d inserted into queue\n", value);
    }
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted from queue\n", queue[front]);
        front++;
    }
}

void display() {
    int i;

    if(front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue Elements:\n");

        for(i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }

    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);

    display();

    dequeue();

    display();

    return 0;
}