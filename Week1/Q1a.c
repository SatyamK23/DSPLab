//C program of implementing Stack using Array
#include<stdio.h>
#include<stdlib.h>

int top=-1;//Stack is empty

//n: StackSize
void push(char elem,char st[],int n)
{
    //Top is at last pos, stackoverflow
    if(top==n-1)
    {
        printf("StackOverflow\n");
    }
    else
    {
        //Incrementing index of top and inserting element into stack
        st[++top]=elem;
    }
  //  display(st);
}

void pop(char st[])
{
    //If stack is empty,underflow condition
    if(top==-1)
    {
        printf("Stack is empty\n");
    //    return;
    }
    //Printing top element which is to be popped
    //Decrementing index of top
    else
    {
        printf("Element poped:%c\n",st[top]);
        --top;
    }
}

//Display the stack status
void display(char st[])
{
    //Stack empty condition
    if(top==-1)
        printf("Stack is empty\n");
        
    else
    {
      for(int i=top;i>=0;i--)
            printf("Element on top %c\t\n",st[i]);
    }
    printf("Size of Stack: %d\t\n", top+1);
}

int main()
{
    int n;
    printf("Enter stack size:");
    scanf("%d",&n);
    char st[n],elem;
    //Inserting element till the stack is full
    //Display stack status and its size
    for(int i=0;i<n;i++)
    {
        printf("Enter character to be inserted");
        scanf(" %c",&elem);
        push(elem,st,n);
        display(st);
    }

    //Emptying the stack after inserting 
    //display stack status and its size
    for(int i=0;i<n;i++)
    {
        pop(st);
        display(st);
    }

    return 0;
}
