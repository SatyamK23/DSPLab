//C-program for Josephus Problem using Linked List
#include <stdio.h>
#include <stdlib.h>

//Create a structure of node
struct Node
{
    int data;
    struct Node *next;
};

//Create a new node as head and no memory is allocated
struct Node *head=NULL;

int survivor(int n)
{
//Create 2 new node 1 node for pointing at starting position
//Another moves in a circle 
//Initially both nodes are assigned as head

    struct Node *p,*q;
    q=head;
    p=head;
    
    //Continue scanning nodes till starting position is reached
    while(p->next!=p)
    {
    //Assign the first node as q
    //Skiping nodes using node p
        for(int i=0;i<n-1;i++)
        {
            q=p;
            p=p->next;
        }
        //Once the circular node is scanned.
        //Next of starting node is updated with the last link of p in previous round
        q->next = p->next;
        printf("%d Killed\n",p->data);
        //The values skipped using p is deleted from memory
        free(p);
        p = q->next;
    }
    
    head = p;
   // free(p);
  //  free(q);
    return p->data;
   
}


void display()
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node *));
    if(head == NULL)
    {
        printf(" No data found in the list");
    }
    else
    {
        //Update tmp to address of head
        tmp = head;
        //display of 1st data
        printf("Linked List: %d ->",tmp->data);
        //Update the address of tmp to next link address
        tmp = tmp->next;
        while(head != tmp)
        {
            //Display of remaining n-1 node data
            printf("%d->",tmp->data);
            //Update the tmp node 
            tmp = tmp->next;
        }
    }
//    free(tmp);
}


//insert at end in a circular linked list
void insert(int x)
{
    //Create 2 node tmp and front
    //Allocate memory to front to store data
    struct Node *tmp;
    struct Node *front = (struct Node*)malloc(sizeof(struct Node*));
    //If the list is empty front is NULL
    if(front == NULL)
        printf("List is empty\n");
    else
    {
        //Adding data to front node
        front->data = x;
        //If no data is inserted
        //Update head
        //Change link of front to head
        if(head == NULL)
        {
            head = front;
            front->next = head;
        }
        else
        {
            //Traverse the list and update tmp
            tmp = head;
            //Add data to last node 
            //Update the tmp
            while(tmp->next!=head)
                tmp = tmp->next;
            //Change the link of tmp to front
            tmp->next = front;
            //Front of next is updated to head to complete the circle
            front->next = head;
        }
    }
//    free(tmp);
}

int main()
{
    int n;
    printf("Enter the no of persons \t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        printf("Enter the data");
        scanf("%d",&data);
        insert(data);
        printf("The person in circular list are :\n");
        display();
    }
    int k;
    printf("\nEnter the no of person to be skipped \t");
    scanf("%d",&k);
    printf("\nThe person survived is %d\n",survivor(k));
    free(head);
    return 0;
}
