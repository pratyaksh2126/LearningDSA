#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode *prev=NULL,*next=NULL;

    while(head)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }

    return prev;
}

struct ListNode* createList(int n)
{
    struct ListNode *head=NULL,*temp=NULL,*newNode;
    int x;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=x;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }

    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    l1=reverse(l1);
    l2=reverse(l2);

    int carry=0;
    struct ListNode *head=NULL;

    while(l1 || l2 || carry)
    {
        int sum=carry;

        if(l1)
        {
            sum+=l1->val;
            l1=l1->next;
        }

        if(l2)
        {
            sum+=l2->val;
            l2=l2->next;
        }

        struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val=sum%10;
        newNode->next=head;
        head=newNode;

        carry=sum/10;
    }

    return head;
}

void printList(struct ListNode* head)
{
    while(head)
    {
        printf("%d ",head->val);
        head=head->next;
    }
}

int main()
{
    int n1,n2;

    scanf("%d",&n1);
    struct ListNode* l1=createList(n1);

    scanf("%d",&n2);
    struct ListNode* l2=createList(n2);

    struct ListNode* result=addTwoNumbers(l1,l2);

    printList(result);

    return 0;
}