#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = 2;

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
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
    stack[0] = 10;
    stack[1] = 20;
    stack[2] = 30;

    display();

    printf("\n");

    pop();

    display();

    return 0;
}