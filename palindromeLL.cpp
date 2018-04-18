/* Program to check if a linked list is palindrome */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
void printList(struct Node *ptr);
/* Link list node */
struct Node
{
    char data;
    struct Node* next;
};
static void reverse(struct Node** head_ref)
{
    if(*head_ref == NULL)
     printf("list is empty");
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
/* Function to check if two input lists have same data*/
bool compareLists(struct Node* head1, struct Node *head2)
{
    while(head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            head1 = head1->next;
            head2 = head2->next;
        }
        else
            return false;
    }
    if(head1 == NULL && head2 == NULL)
        return true;
    return false;
}

/* Function to check if given linked list is
  palindrome or not */
bool isPalindrome(struct Node *head)
{
    if(head == NULL || head->next == NULL)
        return true;
    struct Node *spt = head;
    struct Node *fpt = head;
    struct Node *midnode = NULL;
    struct Node *secondhalf = NULL;
    struct Node *prevofspt = head;
    while(fpt != NULL && fpt->next != NULL)
    {
        prevofspt = spt;
        spt = spt->next;
        fpt = fpt->next->next;
    }
    if(fpt != NULL)
    {
        midnode = spt;
        spt = spt->next;
    }
    secondhalf = spt;
    prevofspt->next = NULL;
    reverse(&secondhalf);
    bool res = compareLists(head,secondhalf);
    reverse(&secondhalf);
    if(midnode != NULL)
    {
        prevofspt->next = midnode;
        midnode->next = secondhalf;
    }
    else
    {
        prevofspt->next = secondhalf;
    }
    return res;
} 

void push(struct Node** head_ref, char new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to pochar to the new node */
    (*head_ref)    = new_node;
}
 
// A utility function to print a given linked list
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    char str[] = "abacaba";
    //char str[] = "aba";
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        push(&head, str[i]);
        printList(head);
        isPalindrome(head)? printf("Is Palindrome\n\n"):
            printf("Not Palindrome\n\n");
    }

    return 0;
}
