#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode *prev = NULL, *next = NULL;

    while(head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverse(slow);

    struct ListNode *temp = head;

    while(slow)
    {
        if(temp->val != slow->val)
            return false;

        temp = temp->next;
        slow = slow->next;
    }

    return true;
}

struct ListNode* createList(int n)
{
    struct ListNode *head = NULL, *temp = NULL, *newNode;
    int x;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = x;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct ListNode* head = createList(n);

    if(isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}