#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int data)//create new node 
{
    struct node* newNode = malloc(sizeof(struct node));//allocate memory for the new node
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void Append(struct node **aRef, struct node **bRef) {

	struct node *aCurrent = *aRef;

	while(aCurrent != NULL) 
    {
		if (aCurrent->next == NULL) 
        {
			return;
		}
		aCurrent = aCurrent->next;
	}
    
	if(aCurrent == NULL) 
    {
		*aRef = *bRef;
	} 
    else 
    {
		aCurrent->next = *bRef;
	}

	*bRef = NULL;
}

void printList(struct node* head)
{
    struct node* current = head;
    while(current != NULL)
    {
        printf("[%d]", current->data);
        current = current->next;
    }
}

int main()
{
   struct node* a = createNode(1);
   struct node* b = createNode(2);
   printf("Before append node 'a' is: ");
   printList(a);

   Append(&a,&b);
   
   printf("\nAfter append node 'a' is: ");
   printList(&a);

   return 0;
}