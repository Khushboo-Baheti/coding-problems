/* C program to check if a tree is height-balanced or not */
#include<stdio.h>
#include<stdlib.h>
#define bool int
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Returns the height of a binary tree */
int height(struct node* node);
 
/* Returns true if binary tree with root as root is height-balanced */
bool isBalanced(struct node *root)
{
    if(root == NULL)
        return 1;
    int hl = height(root->left);
    int hr = height(root->right);
    if(abs(hl-hr) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}
 
/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */
 
/* returns maximum of two integers */
int max(int a, int b)
{
  return (a >= b)? a: b;
}    
 
/*  The function Compute the "height" of a tree. Height is the
    number of nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 0;
    return max(height(node->left),height(node->right))+1;
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 
    if(isBalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");    
 
//    getchar();
    return 0;
}
