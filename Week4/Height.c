//C-program for tree traversal
//REcursive Implementation of finding height
#include<stdio.h>
#include<stdlib.h>

//For finding max of 2 no
#define MAX(a,b) (((a)>(b))?(a):(b))
  
//Creating node of a tree  
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

//Function for finding height of a binary tree
int height(struct Node* root)
{
    //If only root is present
    //Height of tree is 0.
    if(root==NULL)
        return 0;

    return 1+MAX(height(root->left),height(root->right));
}

//Function to insert value to node
struct Node *insert(struct Node *root, int x)
{
    //Creating a tmp node
    struct Node *tmp;

    //Allocating mem to tmp node
    tmp = (struct Node*)malloc(sizeof(struct Node));
    
    //Insert data into tmp node
    tmp->data = x;

    //If value is to be inserted in root
    if(root == NULL)
    {
        tmp->left =NULL;
        tmp->right=NULL;
        root =tmp;
    }

    //Comparing the inserted value with root node
    //If inserted value is less, insert in left node
    if(x<root->data)
        root->left=insert(root->left,x);

    //Else insert in right node
    else if(x>root->data)
        root->right = insert(root->right,x);

    // address of node is returned to calling function
    return root;
}


int main()
{
    //Initialize root to be NULL
    struct Node *root=NULL;
    //No of nodes
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        root = insert(root,x);
    }
     printf("%d\n",height(root));
    free(root);
    return 0;
}
