//C program of Queue using Linked List
#include<stdio.h>
#include<stdlib.h>

//Create node 
struct Node
{
    char data;
    struct Node* next;
};

//Create 2 new node front and rear
//Initialize front and rear to NULL
struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(char elem)
{
    //Create a new node temp  and allocate memory to new node
    //Rear keeps on changing,hence the need of tmp node
    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node*));

    //Assign elem to data of temp node
    tmp->data=elem;
    
    //Queue is full
    if(tmp==NULL)
    {
        printf("Queue Overflow");
        return;
    }
    
    //Similar to front=-1,front is changed to zero
    //Assign front and rear to tmp before proceeding
    //Increment rear by adding new links 
    else if(front==NULL)
    {
        front=tmp;
        rear=tmp;
        front->next = NULL;
        rear->next=NULL;
    }
    else
    {
        rear->next=tmp;
        rear=tmp;
        rear->next=NULL;
    }
}

void dequeue()
{
	//Here front keeps on changing and rear remains fixed
	
    struct Node *tmp;
    if(front==NULL)
    {
        printf("Queue is empty\n");
        exit(1);
    }
    
    //Increment front by deleting links
    else
    {
        tmp=front;
        front=front->next;
        printf("Element deleted is %c\n",tmp->data);
        free(tmp);
    }
}

//Display the queue status 
void display()
{
    struct Node* tmp=front;
    while(tmp!=NULL)
    {
        printf(" %c--> ",tmp->data);
        tmp=tmp->next;
     
    }
    if(tmp==NULL)
        printf("NULL");

    printf("\n");
}

int main()
{
    int n;
    printf("Enter queue size:");
    scanf("%d",&n);
    char elem;
    //Inserting element till the queue size is reached
    //Display queue status 
    for(int i=0;i<n;i++)
    {
        printf("Enter character to be inserted");
        scanf(" %c",&elem);
        enqueue(elem);
        display();
    }

    //Emptying the queue after inserting 
    //display queue status 
    for(int i=0;i<n;i++)
    {
        dequeue();
        display();
    }
    return 0;
}
