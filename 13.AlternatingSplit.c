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
	struct node *newSourceHead = (*sourceRef)->next;

	(*sourceRef)->next = *destRef;
	*destRef = *sourceRef;

	*sourceRef = newSourceHead;
}


void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef) 
{
    *aRef = NULL;
    *bRef = NULL;

    while (source != NULL) 
    {
        if (source->data % 2 == 0) // if the data of current node is even 
        {
            MoveNode(aRef, &source);// move the the current list to node a
            aRef = &((*aRef)->next); //update the reference of 'aRef' to point to the next node 
        } else // If the data of current node is odd
        {
            MoveNode(bRef, &source);// move the current list to node b 
            bRef = &((*bRef)->next);// update the reference of 'aRef' to point to the next node 
        }
    }
}

void PrintList(struct node* head) 
{
    struct node* current = head;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() 
{
    struct node* source = BuildOneTwoThree();
    struct node* aRef = NULL;
    struct node* bRef = NULL;

    AlternatingSplit(source, &aRef, &bRef);

    printf("List aRef: ");
    PrintList(aRef);

    printf("List bRef: ");
    PrintList(bRef);

    return 0;
}
