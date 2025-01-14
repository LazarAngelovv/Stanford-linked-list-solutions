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
        if (a == NULL) 
        {
            *lastElement = b;
            break;
        } 
        else if (b == NULL) 
        {
            *lastElement = a;
            break;
        }
        else 
        {
            if (a->data <= b->data) 
            {
                MoveNode(lastElement, &a);
            }
            else
            {  
                MoveNode(lastElement, &b);
            }
            lastElement = &((*lastElement)->next);
        }
    }
    return newNode;  
}

void MergeSort(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* list1 = NULL;
    struct node* list2 = NULL;

    if (head == NULL || head->next == NULL)
        return;

    FrontBackSplit(head, &list1, &list2);
    
    MergeSort(&list1);
    MergeSort(&list2);
    
    *headRef = SortedMerge(list1, list2);
}

void PrintList(struct node* head)
{
    struct node* current = head;
    while(current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
}

int main()
{
    struct node* myList = BuildOneTwoThree();

    MergeSort(&myList);
    PrintList(myList);

    return 0;
}
