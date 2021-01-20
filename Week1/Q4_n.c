//C-program for evaluation of n-digit postfix expression 

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 100

int stack[20];
int top=0;

//Push the operands into the stack
void push(int a)
{
    printf("Pushing %d at position %d\n",a,top);
    stack[top]=a;
    ++top;
}

//Pop when operator is found
int pop()
{
    printf("Popping %d from position %d and setting stack top to position %d\n", stack[top-1], top-1, top-1);
    top--;
    return stack[top];
}

void evaluate(char c)
{
    int temp1, temp2;
    
    /*If the any of the operator is found,pop 2 operand and perform the arithmetic operation as given in the operator character.
    */
    switch(c)
    {
    case '+':
        temp1=pop();
        temp2=pop();
        printf("Adding %d to %d and going to push result %d\n", temp1, temp2, temp2+temp1);
        push((temp2+temp1));
        break;
    case '-':
        temp1=pop();
        temp2=pop();
        printf("Subtracting %d from %d and going to push result %d\n", temp1, temp2, temp2-temp1);
        push((temp2-temp1));
        break;
    case '*':
        temp1=pop();
        temp2=pop();
        printf("Multiplying %d by %d and going to push result %d\n", temp1, temp2, temp2*temp1);
        push((temp2*temp1));
        break;
    case '/':
        temp1=pop();
        temp2=pop();
        printf("Dividing %d into %d and going to push result %d\n", temp2, temp1, temp2/temp1);
        push((temp2/temp1));
        break;
    }
}



int main()
{
    char *s,*t;
    char *infix[20];
    //Allocating memory to the char s
    s=(char *)malloc(MAX*(sizeof(char)));
    //t=(char *)malloc(MAX*(sizeof(char)));
    //printf("Enter the infix expression");
    //fgets(t,MAX,stdin);
    printf("Enter the postfix expression");
    fgets(s, MAX, stdin);
    char *p, *q[20];
    int i=0;
    //Tokenize the input string between the spaces
    p = strtok(s, " ");
    
    //Till all the string are not tokenize
    //Continue tokenize the string. On reaching the null character exit from the loop
    do{
        q[i] = p;
        infix[i] = p;
        p = strtok(NULL, " ");
        i++;

    }while(p != NULL);

    for(int j=0;j<i;j++)
    {
    //To check if the character is digit or not
    //If the digit is found,convert that digit into integer 
        if(isdigit(*q[j]))
        {
        
            push(atoi(q[j]));

        else
        {
            printf("Found %c as an operator. Going to operate.\n",*q[j]);
            evaluate(*q[j]);
        }
    }

    printf("The result is: %d\n",stack[0]);
    return 0;
}




