#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if(top == MAX - 1)
        printf("Overflow\n");
    else
        stack[++top] = x;
}

void pop() {
    if(top == -1)
        printf("Underflow\n");
    else
        printf("%d\n", stack[top--]);
}

int main() {
    push(10);
    push(20);
    pop();
    return 0;
}