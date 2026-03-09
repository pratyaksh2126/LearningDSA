
//Insert at beggining and end with display - Doubly(Linear) 


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;   
    struct Node* next;
};

struct Node* head = NULL;

void displayList();
void insertNodeatBeginning(int data);
void insertAtEnd(int data);

void insertNodeatBeginning(int data)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;      
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;  

    head = newNode;

    printf("DATA INSERTED AT BEGINNING\n");
}

void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        printf("DATA INSERTED (FIRST NODE)\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;   

    printf("DATA INSERTED AT END\n");
}

void displayList()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("\nDoubly Linked List:\n");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    insertNodeatBeginning(10);
    insertNodeatBeginning(20);

    insertAtEnd(5);
    insertAtEnd(15);

    displayList();

    return 0;
}
