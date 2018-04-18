#include <stdio.h>
#include <stdlib.h>
using namespace std;

// A linked list node
struct Node
{
    int data;
    struct Node *next;
    struct Node *arbit;
};
void append(struct Node** head_ref, int new_data)
{   
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    if(*head_ref == NULL)
    {   
        *head_ref = new_node;
        (*head_ref)->next = NULL;
    }
    else
    {   
        struct Node *temp = *head_ref;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->next = NULL;
    }
}
// This function prints contents of linked list starting from head
void printList(struct Node *node)
{
    struct Node *temp = node;
    printf("data %d \n",temp->data);
    printf("next %d \n",temp->next->data);
    printf("arbit %d \n",temp->arbit->data);
    printf("data %d \n",temp->next->data);
    printf("next %d \n",temp->next->next->data);
    printf("arbit %d \n",temp->next->arbit->data);
    printf("data %d \n",temp->next->next->data);
    printf("next %d \n",temp->next->next->next->data);
    printf("arbit%d \n",temp->next->next->arbit->data);
    printf("data %d \n",temp->next->next->next->data);
    printf("next %d \n",temp->next->next->next->next->data);
    printf("arbit %d \n",temp->next->next->next->arbit->data);
    printf("data %d \n",temp->next->next->next->next->data);
    printf("next NULL \n");
    printf("arbit %d \n",temp->next->next->next->next->arbit->data);
}
void clone(struct Node *head)
{
    struct Node *temp = head;
    struct Node *cln = NULL;
    while(temp != NULL)
    {
        append(&cln,temp->data);
        temp = temp->next;
    }
    struct Node *temp2 = cln;
    temp = head;
    while(temp2 != NULL)
    {
        temp2->arbit = temp;
        temp = temp -> next;
        temp2 = temp2 -> next;
    }
    temp2 = cln;
    temp = head;
    struct Node *t;
    while(temp2 != NULL)
    {
        t = temp->next;
        temp->next = temp2;
        temp2 = temp2->next;
        temp = t;  
    }
    temp2 = cln;
    temp = head;
    while(temp2 != NULL)
    {
        temp2->arbit = temp2->arbit->arbit->next;
        temp2 = temp2->next;
    }
    printList(cln);
}
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    // Insert 6.  So linked list becomes 6->NULL
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    head->arbit = head->next->next;
    head->next->arbit = head;
    head->next->next->arbit = head->next->next->next->next;
    head->next->next->next->arbit = head->next->next;
    head->next->next->next->next->arbit = head->next;
    printf("\n Cloned Linked list is: ");
    printList(head);
    clone(head);

    return 0;
}

