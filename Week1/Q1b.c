//C program of Stack using Linked List
#include<stdio.h>
#include<stdlib.h>

//Create node
struct Node
{
    char data;
    struct Node* next;
};

//Assign memory to top variable
struct Node *top = NULL;

void push(char elem)
{
    //Create a new node temp  and allocate memory to new node
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node*));

    //Assign elem to data of temp node
    temp->data=elem;
    
    //If initial node is empty
    //Assign memory to temp
    if(top == NULL)
    {
        top = temp;
        top->next = NULL;
    }
    
    //
    else
    {
        temp->next = top;
        top=temp;
    }
}

void pop()
{
	//As the top pointer keeps on changing
    //Assign new node temp
    struct Node *temp;
    
    //Stack is empty 
    if(top==NULL)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    
    //Assign address of top to temp and update the top pointer
    //Once element is popped, empty temp memory
    else
    {
        temp=top;
        top=top->next;
        printf("Element popped is %c\n",temp->data);
        free(temp);
    }
}

void display()
{
    struct Node* tmp=top;
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
    printf("Enter stack size:");
    scanf("%d",&n);
    char elem;
    //Inserting element till the stack is full
    //Display stack status and its size
    for(int i=0;i<n;i++)
    {
        printf("Enter character to be inserted");
        scanf(" %c",&elem);
        push(elem);
        display();
    }

    //Emptying the stack after inserting 
    //display stack status and its size
    for(int i=0;i<n;i++)
    {
        pop();
        display();
    }
    return 0;
}
