// C++ program to detect and remove loop
#include<stdio.h>
#include<iostream>
using namespace std;
 
struct Node
{
    int key;
    struct Node *next;
};
 
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
 
// Function to detect and remove loop
// in a linked list that may contain loop
void detectAndRemoveLoop(Node *head)
{
    struct Node *sp = head;
    struct Node *fp = head;
    struct Node *lc = NULL;
    while(fp != NULL && fp->next != NULL)
    {
        fp = fp->next->next;
        sp = sp->next;
        if(fp == sp)
        {
            lc = fp;
            break;
        }
    }
    struct Node *temp = head;
    while(lc != NULL && temp != NULL)
    {
        if(temp->next == lc->next)
            break;
        temp = temp->next;
        lc = lc->next;
    }
    lc->next = NULL;
} 
/* Driver program to test above function*/
int main()
{
    Node *head = newNode(50);
    head->next = head;
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    return 0;
}
