// C/C++ program to find union and intersection of two unsorted 
// linked lists
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
 
/* A utility function to insert a node at the beginning of 
   a linked list*/
void push(struct Node** head_ref, int new_data);
 
/* A utility function to check if given data is present in a list */
bool ispresent(struct Node *head, int data)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}
/* Function to get union of two linked lists head1 and head2 */
struct Node *getUnion(struct Node *head1, struct Node *head2)
{
    struct Node *uniref = NULL;
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;
    while(temp1 != NULL)
    {
        push(&uniref,temp1->data);
        temp1 = temp1->next;
    }
    while(temp2 != NULL)
    {
        if(!(ispresent(uniref,temp2->data)))
            push(&uniref,temp2->data);
        temp2 = temp2->next;
    }
    return uniref;
}
 
/* Function to get intersection of two linked lists
  head1 and head2 */
struct Node *getIntersection(struct Node *head1, 
                              struct Node *head2)
{
    struct Node *intref = NULL; 
    while(head2 != NULL)
    {
        if(ispresent(head1,head2->data))
                push(&intref,head2->data);
        head2 = head2->next;
    }
    return intref;
}
 
/* A utility function to insert a node at the begining of a linked list*/
void push (struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* A utility function to print a linked list*/
void printList (struct Node *node)
{
    while (node != NULL)
    {
        printf ("%d ", node->data);
        node = node->next;
    }
}
 
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersecn = NULL;
    struct Node* unin = NULL;
 
    /*create a linked lits 10->15->5->20 */
    push (&head1, 20);
    push (&head1, 4);
    push (&head1, 15);
    push (&head1, 10);
 
    /*create a linked lits 8->4->2->10 */
    push (&head2, 10);
    push (&head2, 2);
    push (&head2, 4);
    push (&head2, 8);
 
    intersecn = getIntersection (head1, head2);
    unin = getUnion (head1, head2);
 
    printf ("\n First list is \n");
    printList (head1);
 
    printf ("\n Second list is \n");
    printList (head2);
 
    printf ("\n Intersection list is \n");
    printList (intersecn);
 
    printf ("\n Union list is \n");
    printList (unin);
 
    return 0;
}
