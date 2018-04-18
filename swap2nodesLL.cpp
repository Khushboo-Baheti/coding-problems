/* This program swaps the nodes of linked list rather
   than swapping the field from the nodes.*/
 
#include<stdio.h>
#include<stdlib.h>
 
/* A linked list node */
struct Node
{
    int data;
    struct Node *next;
};
 
/* Function to swap nodes x and y in linked list by
   changing links */
void swapNodes(struct Node **head_ref, int x, int y)
{
    struct Node *temp = *head_ref;
    struct Node *prevx = NULL;
    struct Node *currentx = NULL;
    struct Node *prevy = NULL;
    struct Node *currenty = NULL;
    while(temp != NULL)
    {
        if(temp->data == x)
        {
            currentx = temp;
            break;
        }
        prevx = temp;
        temp = temp->next;
    }
    temp = *head_ref;
    while(temp != NULL)
    {
        if(temp->data == y)
        {
            currenty = temp;
            break;
        }
        prevy = temp;
        temp = temp->next;
    }
    if(currenty == NULL || currentx == NULL)
    {
        printf("elements not found\n");
        return;
    }
    if(prevx != NULL)
        prevx->next = currenty;
    else
        *head_ref = currenty;
    if(prevy != NULL)
        prevy->next = currentx;
    else
        *head_ref = currentx;
    struct Node *next  = currenty->next;
    currenty->next = currentx->next;
    currentx->next = next;
}
 
/* Function to add a node at the begining of List */
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
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Druver program to test above function */
int main()
{
    struct Node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling swapNodes() ");
    printList(start);
 
    swapNodes(&start, 4, 3);
 
    printf("\n Linked list after calling swapNodes() ");
    printList(start);
 
    return 0;
}
