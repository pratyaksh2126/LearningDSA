#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    if(top == MAX - 1)
        printf("Overflow\n");
    else {
        stack[++top] = x;
        printf("Pushed %d\n", x);
    }
}

void pop() {
    if(top == -1)
        printf("Underflow\n");
    else
        printf("Popped %d\n", stack[top--]);
}

void display() {
    int i;
    if(top == -1)
        printf("Empty\n");
    else {
        for(i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}