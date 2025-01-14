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
    struct node* fourth = NULL;

    head = malloc(sizeof(struct node)); //allocate 3 nodes in the heap
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));
    fourth = malloc(sizeof(struct node));

    head->data = 1; //setup first node
    head->next = second;//note: pointer assigment rule

    second->data = 2;//setup second node
    second->next = third;

    third->data = 3;//setup third link
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    return head;
}

void FrontBackSplit(struct node *source, struct node **frontRef, struct node **backRef) {

	struct node *fast = source;
	struct node *slow = source;
	struct node *prev = NULL;

	while(fast != NULL)//fast != NULL becouse it moves two times while slow pointer moves once
     {
		//move fast pointer 2 times and slow pointer one time at every iteration
        prev = slow;
		slow = slow->next;//move slow one forward 1
		fast = fast->next;//move fast one forward 1
		
        if (fast == NULL) // if fast != Null
        {
			break;
		}
		fast = fast->next;//move fast one forward 1
	}

	*frontRef = source; //set all the lists to *frontRef
	prev->next = NULL;// cut them where the slow pointer is(in the middle)

	*backRef = slow;//set *backRef to slow so it can accses the backref of the linked list 
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
    struct node* myList = BuildOneTwoThree();
    struct node* list1;
    struct node* list2;

    printList(myList);
    printf("\n");

    FrontBackSplit(myList,&list1,&list2);

    printf("List 1");
    printList(list1);

    printf("\n");

    printf("List 2");
    printList(list2);

    return 0;
}