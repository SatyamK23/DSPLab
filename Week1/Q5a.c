//C-program for implementing stack using queue

//Required Headers
#include<stdio.h>
#include<stdlib.h>

//Create node 
struct Node
{
    char data;
    struct Node *next;
};

//Create 2 new node front and rear
struct queue 
{
    struct Node *front;
    struct Node *rear;
};

//Initialize front and rear to NULL
void initialize(struct queue *q)
{
    q->front=NULL;
    q->rear=NULL;
}

struct queue q1,q2;
//int size=0;
void enqueue(struct queue *q, char elem)
{
    //Create a new node temp  and allocate memory to new node
    //Rear keeps on changing,hence the need of tmp node
    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node*));

    //Assign elem to data of temp node
    tmp->data = elem;
    
    tmp->next = NULL;
    //Similar to front=-1,front is changed to zero
    //Assign front and rear to tmp before proceeding
    //Increment rear by adding new links 
    if(q->front==NULL)
    {
        q->rear=tmp;
        q->front=tmp;
        return;
    }
   
   q->rear->next=tmp;
   q->rear=tmp;
      //  q->rear->next=NULL;
}

int dequeue(struct queue *q)
{
	//Here front keeps on changing and rear remains fixed
	
    struct Node *tmp;
    char elm;
    
    //Increment front by deleting links
    if(q->front==NULL)
    {
    	printf("Queue is empty\n");
    	return 0;
    }
    
        tmp=q->front;
        elm=tmp->data;
        q->front=tmp->next;
       // printf("Element deleted is %c\n",tmp->data);
        free(tmp);
    return elm;
}

/*
void display(struct queue *q)
{
    struct node *tmp;
    tmp=q->front;
    while((tmp)!=NULL)
    {
        printf("\n%c",(tmp->data));   
        tmp=tmp->next;
    }
    printf("\n");
}*/


void push(char val)
{
    struct queue tmp;
    char j;
    enqueue(&q2,val);
   
    while(((&q1)->front)!=NULL)
    {
        j=dequeue(&q1);
        enqueue(&q2,j);
    }

   
    tmp=q1;  //swap q1 and q2
    q1=q2;
    q2=tmp;

    //printf("\nelements after pushing are:\n");
   // display(&q1);

}

void pop()
{
     printf("Element popped is %c",dequeue(&q1));
   // pop(q1);
}


int main()
{
    struct queue q1,q2;
    initialize(&q1);
    initialize(&q2);
    push('5' -'0');
    push('6'-'0');
    push('7'-'0');
    pop();
 
   
    /* int n;
    printf("Enter queue size:");
    scanf("%d",&n);
    char elem;
    //Inserting element till the queue size is reached
    //Display queue status 
    for(int i=0;i<n;i++)
    {
        printf("Enter character to be inserted");
        scanf(" %c",&elem);
        push(elem);
        display(q1);
    }

    //Emptying the queue after inserting 
    //display queue status 
    for(int i=0;i<n;i++)
    {
        pop();
        display(q1);
    }
     */
    return 0;
}
