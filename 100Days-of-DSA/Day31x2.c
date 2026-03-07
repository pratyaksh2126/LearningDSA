#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node* head = NULL;
int size = 0;

int get(int index){
    if(index < 0 || index >= size) return -1;
    struct Node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->val;
}

void addAtHead(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = head;
    head = newNode;
    size++;
}

void addAtTail(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void addAtIndex(int index,int val){
    if(index < 0 || index > size) return;

    if(index == 0){
        addAtHead(val);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;

    struct Node* temp = head;
    for(int i = 0; i < index-1; i++){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

void deleteAtIndex(int index){
    if(index < 0 || index >= size) return;

    struct Node* temp = head;

    if(index == 0){
        head = temp->next;
        free(temp);
    }else{
        for(int i = 0; i < index-1; i++){
            temp = temp->next;
        }
        struct Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
    size--;
}

void display(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    addAtHead(1);
    addAtTail(3);
    addAtIndex(1,2);

    printf("%d\n",get(1));

    deleteAtIndex(1);

    printf("%d\n",get(1));

    display();

    return 0;
}