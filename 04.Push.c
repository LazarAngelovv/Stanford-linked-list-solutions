#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* BuildOneTwoThree()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node)); //allocate 3 nodes in the heap
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1; //setup first node
    head->next = second;//note: pointer assigment rule

    second->data = 2;//setup second node
    second->next = third;

    third->data = 3;//setup third link
    third->next = NULL;

    return head;
}

void Push(struct node** headRef, int data) 
{
    struct node* newNode = malloc(sizeof(struct node));
    
    newNode->data = data;
    newNode->next = *headRef; // The '*' to dereferences back to the real head
    *headRef = newNode; 
}

void printList(struct node* head)
{
    struct node* current = head;
    while(current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{ 
    struct node* myList = BuildOneTwoThree();
    Push(&myList,1);
    Push(&myList,13);

    printList(myList);
    
    return 0;
}