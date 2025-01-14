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

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

void Reverse(struct node** head)
{
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = current->next;

    while(current != NULL)
    {
        next = current->next;// Store the next node before modifying the pointer.
        current->next = prev;// Reverse the pointer of the current node to point to the previous node.

        prev = current;// Move the previous node pointer to the current node.
        current = next;// Move the current node pointer to the next node.
    }

    *head = prev;
}

void PrintList(struct node* node)
{
    struct node* current = node;

    while(current != NULL)
    {
        printf("%d",current->data);
        current = current->next;
    }
}

int main()
{
    struct node* myList = BuildOneTwoThree();
    Reverse(&myList);
    PrintList(myList);
    
    return 0;
}