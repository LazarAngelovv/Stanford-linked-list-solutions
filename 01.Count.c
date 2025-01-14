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

int Count(struct node* head, int searchNumber)
{
    struct node* current = head;
    int count = 0;
   
    while (current != NULL) 
    {
        if(current->data == searchNumber)
        {
            count++;
        }
        current = current->next;
    }
    return count;
}

void CountTest() 
{
    struct node* myList = BuildOneTwoThree(); // build {1, 2, 3}
    int count = Count(myList, 2); // returns 1 since there's 1 '2' in the list
    
    printf("%d", count);
}   

int main()
{
    CountTest();

    return 0;
}