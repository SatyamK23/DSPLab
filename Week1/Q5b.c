//C-program for implementing queue using stack

//Required Headers
#include<stdio.h>
#include<stdlib.h>

//Initialize top of 2 stacks
int top1=-1,top2=-1;

//Push an element into stack1
void push1(int elem,int stack1[], int n)
{
    //If top1 is less than size
    //Continue adding elements into stack1
        stack1[++top1]=elem;
}

//Function to Pop an element from stack1 
int pop1(int stack1[])
{
    //First top index is decreased and element is deleted from stack
   return  stack1[top1--];
}


//Push an element into stack2
void push2(int elem,int stack2[], int n)
{

    //If top2 is less than size
    //Continue adding elements into stack2

        stack2[++top2]=elem;
}

//Function to Pop an element from stack2
int pop2(int stack2[])
{
     return (stack2[top2--]);
}

//To enqueue an element into queue using stacks
void enqueue(int elem,int stack1[],int n)
{
    //Push an element into stack1
    push1(elem,stack1,n);
}

void dequeue(int elem,int stack1[],int stack2[],int n)
{
    //char elem;
    //Pop elements from stack1 and push into stack
    
    //else if(top1==0)
     
    if(top1==-1)
    {
        printf("EMPTY QUEUE\n");
        return;
    }
    int data;
    for(int i=0;i<=n;i++)
    {
        data=pop1(stack1);
        push2(data, stack2,n);
        //pop2(stack2[n--]);
    }
    pop2(stack2);
    n--;
    for(int i=0;i<=n;i++)
    {
        data=pop2(stack2);
        push1(data,stack1,n);
    }
}

void display(int stack1[])
{
    if(top1==-1)
    {
        printf("EMPTY QUEUE\n");
        return;
    }
        for(int i=0;i<top1+1;i++)
            printf("Elements of queue %d ",stack1[i]);

        printf("\n");
    
}

int main()
{
    int n;
    printf("Enter the no of elemens in queue");
    scanf("%d",&n);
    int choice;
    printf("1.Enqueue\n2.Dequeue\n3.Exit\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        int elem;
        int stack1[n],stack2[n];
        switch(choice)
        {
            case 1:
                printf("\n Enter the character to be inserted ");
                scanf("%d",&elem);
                enqueue(elem,stack1,n);
                display(stack1);
                break;
            case 2:
                dequeue(elem,stack1,stack2,n);
                display(stack1);
                break;
            default:
                printf("Exiting ...");
                exit(0);
                break;
        }
    }
    return 0;
}
