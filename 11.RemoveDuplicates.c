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

    head->data = 2; //setup first node
    head->next = second;//note: pointer assigment rule

    second->data = 2;//setup second node
    second->next = third;

    third->data = 3;//setup third link
    third->next = NULL;

    return head;
}

void RemoveDuplicates(struct node *head) {

	struct node *current = head;
	struct node *temp = NULL;

	while(current != NULL) 
        {
		if (current->next != NULL && current->data == current->next->data) 
        {
			temp = current->next;//save the pointer in temp
			current->next = current->next->next;
			temp->next = NULL;
			free(temp);//delete duplicate item 
		} 
	        else
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
        printf("[%d]\n", current->data);
        current = current->next;
    }
}

int main()
{
    struct node* myList = BuildOneTwoThree();
    printf("List before 'RemoveDuplicates'\n" );
    printList(myList);

    RemoveDuplicates(myList);

    printf("List after 'RemoveDuplicates'\n" );
    printList(myList);

    return 0;
}

