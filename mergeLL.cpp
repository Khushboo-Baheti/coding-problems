/* C/C++ program to merge two sorted linked lists */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
 
/* Takes two lists sorted in increasing order, and splices
   their nodes together to make one big sorted list which
   is returned.  */
void insert(struct Node **head_ref,int data)
{
    if((*head_ref)->next == NULL)
    {
        struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
        new_node->data = data;
        (*head_ref)->next = new_node;
        *head_ref = (*head_ref)->next;
        (*head_ref)->next=NULL;
    }
}
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    struct Node *temp = new_node;
    struct Node *res = new_node;
    if(a->data <= b->data)
    {
        new_node->data = a->data;
        a = a->next;
    }
    else
    {
        new_node->data = b->data;
        b= b->next;
    }
    new_node->next = NULL;
    while( a != NULL && b != NULL)
    {
        if(a->data <= b->data)
        {
            insert(&temp,a->data);
            a = a->next;
        }
        else
        {
            insert(&temp,b->data);
            b = b->next;
        }
    }
    while(a != NULL)
    {
        insert(&temp,a->data);
            a = a->next;
    }
    while(b != NULL)
    {
        insert(&temp,b->data);
            b = b->next;
    }
    temp->next = NULL;
    return res;
}
 
/* Function to insert a node at the beginging of the
   linked list */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;
 
    /* Let us create two sorted linked lists to test
      the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
 
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
 
    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);
 
    printf("Merged Linked List is: \n");
    printList(res);
 
    return 0;
}
