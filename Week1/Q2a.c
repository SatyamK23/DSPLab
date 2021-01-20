#include<stdio.h>
#include<limits.h>

//const int N=20;
int front=-1,rear=-1,n;

//Inserting element into queue
void enqueue(char elem, char queue[])
{
    //Queue is full
    if(rear==n-1)
    {
        printf("Overflow\n");
        return;
    }
    
    //Assign front=0 to 1st element of queue
    //Front remains fixed,rear increments by 1 on each addition  
    else
    {
        if(front ==-1)
            front=0;
        //Incrementing index of rear and inserting element into queue
        queue[++rear]=elem;
    }
}

void dequeue(char queue[])
{

	//Queue is empty
    if(front>rear || front==-1)
    {
        printf("Underflow\n");
        return;
    }
    
    //Rear remains fixed, front increases
    else
    {
        front++;
    }
}

int main()
{
   printf("Enter the size of queue");
   scanf("%d",&n);
   char queue[n+1],elem;
   
   //Inserting element till the queue is full
    //Display queue status and its size
  	for(int i=0;i<n;i++)
    {
        printf("Enter character to be inserted");
        scanf(" %c",&elem);
        //elem = queue[++front];
        enqueue(elem,queue);
        //printf("Size of queue %d",rear+1);
        printf("Element inserted %c \n", queue[i]);
        printf("Size of queue: %d\n",(rear-front+1));
    }

	
    //Emptying the queue after inserting elements
    for(int i=0;i<n;i++)
    {
        dequeue(queue);
        printf("Element deleled from queue %c \n",queue[i]);
    }

    return 0;
}
