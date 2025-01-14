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

int Pop(struct node** headRef)
{
    struct node* head = *headRef; // pointer to head
    int data = head->data; //store the data before the node is deleted
 
    (*headRef) = (*headRef)->next; //unlink the node                           
    free(head);            
 
    return data;          
}
void printList(struct node* head)
{
    while(head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}
void PopTest() 
{
    struct node* head = BuildOneTwoThree(); // build {1, 2, 3}
    int a = Pop(&head); // deletes "1" node and returns 1
    int b = Pop(&head); // deletes "2" node and returns 2
    int c = Pop(&head); // deletes "3" node and returns 3
}

int main()
{
    struct node* myNode = BuildOneTwoThree();

    PopTest();
    printList(myNode);

    return 0;
}