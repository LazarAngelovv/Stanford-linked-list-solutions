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

struct node* createNode(int data)//create new node 
{
    struct node* newNode = malloc(sizeof(struct node));//allocate memory for the new node
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void SortedInsert(struct node** headRef, struct node* newNode)
{
    struct node* current = *headRef;//deref pointer to head
    
    if(newNode->data == 0)
    {
        newNode->next = current->next;
        *headRef = newNode;

        return;
    }

    while (current->next != NULL)
    {
        if(current->data <= newNode->data && newNode->data <= current->next->data )//if the previous node data is smaller then new node and the next node data is bigger thennewNode place the newNode between them 
        {
            newNode->next = current->next;
            current->next = newNode;
            
            return;
        }
        else//else iterate over the linked list
        {
            current = current->next;
        }
    }
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
    struct node* newNode = createNode(1);
    struct node* oldList = BuildOneTwoThree();
    SortedInsert(&oldList,newNode);
    printList(oldList);
    
    return 0;
}