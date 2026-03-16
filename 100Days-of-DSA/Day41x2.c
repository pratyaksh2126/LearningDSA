#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1, size = 0, capacity;

int isFull(){
    return size == capacity;
}

int isEmpty(){
    return size == 0;
}

int insertFront(int x){
    if(isFull()) return 0;

    if(isEmpty()){
        front = rear = 0;
    }else{
        front = (front - 1 + capacity) % capacity;
    }

    deque[front] = x;
    size++;
    return 1;
}

int insertLast(int x){
    if(isFull()) return 0;

    if(isEmpty()){
        front = rear = 0;
    }else{
        rear = (rear + 1) % capacity;
    }

    deque[rear] = x;
    size++;
    return 1;
}

int deleteFront(){
    if(isEmpty()) return 0;

    if(front == rear){
        front = rear = -1;
    }else{
        front = (front + 1) % capacity;
    }

    size--;
    return 1;
}

int deleteLast(){
    if(isEmpty()) return 0;

    if(front == rear){
        front = rear = -1;
    }else{
        rear = (rear - 1 + capacity) % capacity;
    }

    size--;
    return 1;
}

int getFront(){
    if(isEmpty()) return -1;
    return deque[front];
}

int getRear(){
    if(isEmpty()) return -1;
    return deque[rear];
}

int main(){
    capacity = 3;

    insertLast(1);
    insertLast(2);
    insertFront(3);
    printf("%d\n", insertFront(4));
    printf("%d\n", getRear());
    printf("%d\n", isFull());
    printf("%d\n", deleteLast());
    printf("%d\n", insertFront(4));
    printf("%d\n", getFront());

    return 0;
}