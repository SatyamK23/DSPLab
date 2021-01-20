#include<stdio.h>
#include<stdlib.h>
//Create structure of Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int n;
//Initialize the Node parameters
struct Node *node(int data)
{
    struct Node *tmp =(struct Node *) malloc( sizeof(struct Node *));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
 
}

/*
int search(int in[], int x)
{
    for(int i=0;i<n;i++)
    {
        if(in[i]==x)
            return i;
    }
}
*/

struct Node *built_tree(int in[], int inStart,int inEnd,int post[],int postStart,int postEnd)
{
    if(inStart>inEnd || postStart > postEnd) 
        return NULL;
    int rootValue = post[postEnd];
    struct Node *root = node(rootValue);

    if(inStart==inEnd)
        return root;

    int k=0;
    //TO handle duplicates
    for(int i=inStart;i<=inEnd;i++)
    {
        if(in[i]==rootValue)
        {
            k=i;
            break;
        }
    }
    root->left = built_tree(in, inStart,k-1,post,postStart,postStart + k - (inStart + 1));
    root->right = built_tree(in,k+1,inEnd, post, postStart + k- inStart, postEnd - 1);
return root;
}

void preOrder(struct Node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    scanf("%d",&n);
    int inOrder[n],postOrder[n];
    for(int i=0;i<n;i++)
        scanf("%d",&inOrder[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&postOrder[i]);
    
    struct Node *root = built_tree(inOrder, 0,n-1, postOrder,0,n-1);
    preOrder(root);
   free(root);
    return 0;
}
