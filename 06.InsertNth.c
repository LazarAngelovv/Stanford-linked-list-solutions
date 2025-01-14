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

struct node* createNode(int inputData)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = inputData;
    newNode->next = NULL;

    return newNode;
}

void InsertNth(struct node** headRef,int index, int data)
{
    struct node* newNode = createNode(data);
    struct node* current = *headRef;
    
    if(index == 0)// if index equal "0" we are on firs node
    {
        newNode->data = data;
        newNode->next = current->next;
        *headRef = newNode;//set head pointer to point to newNode

        return;
    }
    int count = 1;//count of every loop iteration == node in the list (1 iteration = first node 2 iteration = second node...)
    while(current->next != NULL)
    {
        if(index == count)// if index(user input) == count(count of every loop iteartion) (newNode->next = current->next)(current->next = newNode)
        {
            newNode->data = data;
            newNode->next = current->next;
            current->next = newNode;
            
            return;
        }
        else
        {
            current = current->next;//countinue iterate over the linked list
        }
        count++;
    }
    printf("Invalid index");
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
    InsertNth(&myList,0,13);
    InsertNth(&myList,1,42);
    InsertNth(&myList,1,5);
    printList(myList);

    return 0;
}