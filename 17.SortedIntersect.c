#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int data)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct node* BuildOneTwoThree()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

struct node* BuildOneTwo()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 23;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 2;
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

struct node* SortedIntersect(struct node* a, struct node* b) 
{
    struct node* result = NULL;
    struct node** lastNode = &result;

    while (a != NULL && b != NULL) 
    {
        if (a->data == b->data) 
        {
            // Create a new node for the intersection list
            struct node* newNode = (struct node*)malloc(sizeof(struct node));
            newNode->data = a->data;
            newNode->next = NULL;
            // Append the new node to the intersection list
            *lastNode = newNode;
            lastNode = &(newNode->next);
            // Move both pointers to the next nodes
            a = a->next;
            b = b->next;
        } 
        else if (a->data < b->data) 
        {
            // Move pointer a to the next node
            a = a->next;
        } 
        else 
        {
            // Move pointer b to the next node
            b = b->next;
        }
    }
    return result; 
}

void PrintList(struct node* head)
{
    struct node* current = head;
    while(current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
}

int main()
{
    struct node* a = BuildOneTwoThree();
    struct node* b = BuildOneTwo();
    struct node* result = SortedIntersect(a,b);;
   
    PrintList(result);
}