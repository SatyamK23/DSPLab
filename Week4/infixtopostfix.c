//C-program for Infix to Postfix using Linked List implementation of stack
//Library for standard input
#include<stdio.h>
//For dynamic memory allocation
#include<stdlib.h>
//For using strlen
#include<string.h>

//Creating a structure of node
struct Node
{

	char data;
	struct Node *next;
};
//Node is for finding location of Top
struct Node *top=NULL;
struct Node *pstart=NULL;

//Inserting the infix expression char by char
void insert(char ch)
{
    //2 Temporary node for storing character 
    //Other node for traversing of character till an operator is found
	struct Node *tmp1,*tmp2;
    tmp2 =(struct Node *)malloc(sizeof(struct Node *));
    tmp2->next=NULL;
    tmp2->data=ch;
    //Storing operator 
    tmp1 = pstart;

    if(pstart==NULL)
    {
    	pstart=tmp2;
    }
    else
    {
		while(tmp1->next!=NULL)
			tmp1=tmp1->next;
		tmp1->next=tmp2;

    }
}

void push (char symbol)
{

    struct Node *p=(struct Node *)malloc(sizeof(struct Node *));
    p->data=symbol;
    if(top==NULL)
    {
		 top=p;
		 p->next=NULL;
    }
    else
    {
		p->next=top;
		top=p;
    }
}

char  pop()
{
	struct Node *x,*y;
	char k;
	if(top==NULL)
	{
		exit (1);

	}
	else
	{
		x=top;
		top=top->next;
		k=x->data;
		free(x);
		x=NULL;
		return k;
	}
}

//For printing postfix exp using infix expr
void displaypost()
{
    struct Node *tmp;
    if(pstart==NULL)
    	printf("");
    else
    {
		tmp=pstart;
		while(tmp!=NULL)
		{
		    printf("%c",tmp->data);
		    tmp = tmp->next;
		}

    }
}

//Setting precedence of operator
int precedence(char ch)
{

	if(ch=='%')
		return (5);
	else if(ch=='*' || ch== '/')
		return (4);
	else if (ch== '+' || ch== '-')
		return (3);
	else
		return (2);
}


void intopost(char infix[])
{
    int index=0;
    char symbol,temp;
    int len = strlen(infix);
    while(len>index)
    {
        symbol=infix[index];
        switch(symbol)
        {
        //Push the ( into stack
            case '(':
            push(symbol);
            break;
        //If the ) is found
        //Pop the last operand
            case ')':
            temp=pop();
        //Continue scanning and if ( is found in between expr
        //Insert the character
        //Convert the ( part into postfix 
            while(temp!='(')
            {
                insert(temp);
                temp=pop();
            }
            break;
//If an operator is found, compare the predence of operator from the precedence func
        case '%':
        case '+':
        case '-':
        case '*':
        case '/':
        if(top==NULL)
        {
            push(symbol);
        }
        else
        {
        while(top!=NULL && (precedence(top->data)>=precedence(symbol)))
        {
            temp=pop();
            insert(temp);

        }
        push(symbol);

        }   
        break;
        default:
        insert(symbol);

         }
         index=index+1;
    }
    while(top!=NULL)
    {
    temp=pop();
    insert(temp);

    }
    displaypost();
    return;
}


int main()
{
    char infix[50];
    fgets(infix,50,stdin);
    intopost(infix);
    return 0;
}

