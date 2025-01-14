#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

void RecursiveReverse(struct node **headRef) 
{
	if (*headRef == NULL) // Exit if the linked list is empty
    {
		return;
	}

	if((*headRef)->next == NULL) // Exit if there is only one node in the linked list
    {
		return;
	}
	
    struct node *prevHead = *headRef; // Store the original head node
	*headRef = (*headRef)->next;// Move the head pointer to the next node
	
    RecursiveReverse(headRef);// Recursively reverse the rest of the linked list
	
    prevHead->next->next = prevHead;// Reverse the link between the current node and the previous node
	prevHead->next = NULL;// Mark the end of the reversed linked list
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
    PrintList(myList);
    
    RecursiveReverse(&myList);
    PrintList(myList);
    
    return 0;
}