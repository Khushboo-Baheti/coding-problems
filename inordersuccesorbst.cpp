// A recursive C program to find LCA of two nodes n1 and n2.
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* left, *right;
};
 
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = node->right = NULL;
    return(node);
}
int insuc(struct node *root,int n)
{
    int res = -1;
    while(root != NULL)
    {
    if(root->data > n)
    {
        res = root->data;
        root = root->left;
    }
    else if(root->data <= n)
        root = root->right;
    }
    return res;
}

 
/* Driver program to test lca() */
int main()
{
    // Let us construct the BST shown in the above figure
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n = 8;
    int res = insuc(root, n);
    printf("inorder succesor of %d is  %d  \n",n,res);
    return 0;
}
