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

void MoveNode(struct node** destRef, struct node** sourceRef) 
{
    struct node* newSourceHead = (*sourceRef)->next; // create a new pointer to hold the next node of the source list
   
    (*sourceRef)->next = *destRef;   // update the next pointer of the source node to point to the destination list

    *destRef = *sourceRef; // move the destination reference to the source node, making it the new head of the destination list

    *sourceRef = newSourceHead; // update the source reference to point to the next node in the source list
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
    struct node* a = BuildOneTwoThree();
    struct node* b = BuildOneTwoThree();

    PrintList(a);
    PrintList(b);
    
    MoveNode(&a, &b);   

    PrintList(a);

    printf("\n");
    PrintList(b);

    return 0;
}