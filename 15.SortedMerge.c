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

    head->data = 3;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 7;
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

    head->data = 2;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
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

struct node* SortedMerge(struct node* a, struct node* b) 
{
    struct node* newNode = NULL;
    struct node** lastElement = &newNode;

    while (a != NULL || b != NULL) 
    {
        if (a == NULL) // if "a" is NULL point to  "b"
        {
			*lastElement = b;
			break;
		} 
        else if (b == NULL) // if "b" is NULL point to "a"
        {
			*lastElement = a;
            break;
		}
        else 
        {
            if (a->data <= b->data) // if  "a->data"  is equal or smaller then "b->data"
            {
                MoveNode(lastElement, &a);//move last element from "a"  to lastElement(newNode)
            }
            else
            {  
                MoveNode(lastElement, &b); //move last element from "a"  to lastElement(newNode)
            }
            lastElement = &((*lastElement)->next); //moove the pointer to point the next  element in the list;
        }
    }
    return newNode;  
}
void PrintList(struct node* head)
{
    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->next; 
    }
}

int main()
{
   struct node* a = BuildOneTwoThree();
   struct node* b = BuildOneTwo();
   struct node* newNode = SortedMerge(a,b);
   PrintList(newNode);

    return 0;
}