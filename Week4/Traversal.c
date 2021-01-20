//C-program for tree traversal
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


void PreOrder(struct Node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct Node *root)
{
    if (root == NULL) 
          return; 
  
     /* first recur on left child */
     InOrder(root->left); 
  
     /* then print the data of node */
     printf("%d ", root->data);   
  
     /* now recur on right child */ 
     InOrder(root->right); 
}

void PostOrder(struct Node *root)
{
    if (root == NULL)
        return;

     // first recur on left subtree
     PostOrder(root->left);

     // then recur on right subtree
     PostOrder(root->right);

     // now deal with the node
     printf("%d ", root->data);
}

struct Node *insert(struct Node *root, int x)
{
    struct Node *tmp;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = x;

    if(root == NULL)
    {
        tmp->left =NULL;
        tmp->right=NULL;
        root =tmp;
    }



    if(x<root->data)
        root->left=insert(root->left,x);

    else if(x>root->data)
        root->right = insert(root->right,x);

    return root;
}

int main()
{
    struct Node *root=NULL;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        root = insert(root,x);
    }
     PreOrder(root);
      printf("\n");
      InOrder(root);
        printf("\n");
        PostOrder(root);
        printf("\n");
    free(root);
    return 0;

}
