
//At beggining and end merged code with display - Singly(Linear)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void displayList();
void insertNodeatBeginning(int data);
void insertAtEnd(int data);

void insertNodeatBeginning(int data)
{
    struct Node *newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }

    newNode->data = data;
    newNode->next = head;
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
        head = newNode;
        printf("DATA INSERTED (FIRST NODE)\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

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

    printf("\nCurrent Linked List:\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
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
