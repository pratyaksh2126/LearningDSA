#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value) {
    if(top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

void display() {
    if(top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack Elements: ");
        for(int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    return 0;
}