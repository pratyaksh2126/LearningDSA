#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push1(int x){
    s1[++top1] = x;
}

int pop1(){
    return s1[top1--];
}

void push2(int x){
    s2[++top2] = x;
}

int pop2(){
    return s2[top2--];
}

bool empty2(){
    return top2 == -1;
}

void push(int x){
    push1(x);
}

int pop(){
    if(empty2()){
        while(top1 != -1){
            push2(pop1());
        }
    }
    return pop2();
}

int peek(){
    if(empty2()){
        while(top1 != -1){
            push2(pop1());
        }
    }
    return s2[top2];
}

bool empty(){
    return top1 == -1 && top2 == -1;
}

int main(){
    int n,x;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        push(x);
    }

    printf("%d\n",peek());
    printf("%d\n",pop());

    if(empty())
        printf("true\n");
    else
        printf("false\n");

    return 0;
}