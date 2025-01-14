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

int GetNth(struct node* head, int listIndex)
{
    struct node* current = head;
    int count = 0;
    
    while (current != NULL) 
    {
        if(count == listIndex)
        {
            return current->data;
        }
        else
        {
            count++;
            current = current->next;
        }
    }

    return -1;
}

void GetNthTest() 
{
    struct node* myList = BuildOneTwoThree(); // build {1, 2, 3}
    int getn = GetNth(myList, 2); // returns 1 since there's 1 '2' in the list
    
    printf("%d\n", getn);
}

int main()
{
    GetNthTest();

    return 0;
}