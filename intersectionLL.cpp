#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct Node
{
  int data;
  struct Node* next;
};
 
/* Function to get the counts of node in a linked list */
int getCount(struct Node* head);
 
/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
int getnode(int d, struct Node* head1, struct Node* head2);
 
/* function to get the intersection point of two linked
   lists head1 and head2 */
int getIntersectionNode(struct Node* head1, struct Node* head2)
{
    int n = getCount(head1);
    int m = getCount(head2);
    int d;
    int res = 0;
    if(n > m)
    {
        d = n - m;
        res = getnode(d,head1,head2);
    }
    else
    { 
        d = m-n;
        if(d != 0)
        {
            res = getnode(d,head2,head1);
        }
    }
    return res;
}
 
/* function to get the intersection point of two linked
   lists head1 and head2 where head1 has d more nodes than
   head2 */
int getnode(int d, struct Node* head1, struct Node* head2)
{
    int count = 1;
    int res = 0;
    while(count <= d)
    {
        head1 = head1->next;
        count++;
    }
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->next == head2->next)
        {
            res = head1->next->data;
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
    } 
    return res;
}
 
/* Takes head pointer of the linked list and
   returns the count of nodes in the list */
int getCount(struct Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
 
/* IGNORE THE BELOW LINES OF CODE. THESE LINES
   ARE JUST TO QUICKLY TEST THE ABOVE FUNCTION */
int main()
{
  /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 10->15->30
 
    15 is the intersection point
  */
 
  struct Node* newNode;
  struct Node* head1 =
            (struct Node*) malloc(sizeof(struct Node));
  head1->data  = 10;
 
  struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
  head2->data  = 3;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          getIntersectionNode(head1, head2));
}
