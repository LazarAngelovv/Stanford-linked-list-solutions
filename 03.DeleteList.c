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

void DeleteList(struct node** headRef)
{
    //deref headRef to get the real head
    struct node* current = *headRef;
    struct node* next;

    while (current != NULL) 
    {
        next = current -> next;
        free(current);
        current = next;
    }
    *headRef = NULL;
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
    printf("Print before delete..\n");
    printList(myList);

    DeleteList(&myList);

    printf("Print after delete...\n");
    printList(myList);
    printf("There is nothing :D\n");

    return 0;
}