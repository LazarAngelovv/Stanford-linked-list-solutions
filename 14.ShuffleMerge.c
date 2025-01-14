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

    second->data = 2;
    second->next = third;

    third->data = 1;
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

    head->data = 1;
    head->next = second;

    second->data = 13;
    second->next = third;

    third->data = 7;
    third->next = NULL;

    return head;
}

void MoveNode(struct node** destRef, struct node** sourceRef) 
{
    struct node* newSourceHead = (*sourceRef)->next;

    (*sourceRef)->next = *destRef;
    *destRef = *sourceRef;

    *sourceRef = newSourceHead;
}

struct node* ShuffleMerge(struct node* a, struct node* b)
{
    struct node* shuffleList = NULL;

    while (a != NULL && b != NULL)// Continue the loop until 'a' and 'b' becomes NULL
    {
        MoveNode(&shuffleList, &a);// Move the node from list 'a' to the shuffle list
        MoveNode(&shuffleList, &b);// Move the node from list 'b' to the shuffle list
    }

    return shuffleList;// Return the resulting shuffled list
}

void PrintList(struct node* head) 
{
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct node* a = BuildOneTwoThree();
    struct node* b = BuildOneTwo();
    struct node* shuffleList = ShuffleMerge(a, b);

    printf("ShuffleList: ");
    PrintList(shuffleList);

    return 0;
}
