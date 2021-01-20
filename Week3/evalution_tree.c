//Program for building expression tree and evaluation of infix expression
#include<stdio.h> //For std input/ouptut
#include<stdlib.h> //For dynamic memory allocation
#include<stdbool.h> //For using bool variable
#include<math.h> //for power function
#include<string.h> //for using strlen

//Node structure
typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
}*Btree;

Btree root;
int top=-1;
Btree stack[100];
char expr[100];

/*Create Node
ExpTree node(int info)
{
    typedef struct Node *tmp=(typedef struct Node *) malloc(sizeof(typedef struct Node *));
    
    if(tmp==NULL)
    {
        return (tmp);
    }
    tmp->data = info;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
*/
void push(Btree root)
{
    stack[++top] = root;
}

Btree pop()
{
    return (stack[top--]);
}

int peek()
{
    return stack[top];
}

void operandFunc(char var)
{
    Btree root = (Btree)malloc(sizeof(struct Node));
    root->data= var;
    root->left= NULL;
    root->right= NULL;
    push(root);
}

void operatorFunc(char var)
{
    Btree root = (Btree)malloc(sizeof(struct Node));
    root->data = var;
    root->right = pop();
    root->left = pop();
    push(root);
}


bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/'  || ch == '^' || ch=='(' ||ch==')')
		return true;
	return false;
}


int getPriority(char ch)
{
	switch (ch)
	{
	case '^':
		return 3;
	case '/':
	case '*':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

bool isDigit(char ch)
{
    if(ch>='0' && ch<='9')
        return true;

    return false;
}

//Function for evaluation of infix expression
int cal(char operator, int op1, int op2)
{
    switch(operator)
    {
        case '+':
            return (op1+op2);
            break;
        case '-':
            return (op1 - op2);
            break;
        case '*':
            return (op1 *op2);
            break;
        case '/':
            return (op1/op2);
            break;
        case '^':
            return pow(op1,op2);
            break;
        default:
            printf("Invalid");
            break;
    }
}
//Function for building infix expression tree
int solve(Btree root)
{
    Btree tmp = root;
    char num1,num2,operator;
    int result;
    if(tmp)
    {
        Btree LEFTp = tmp->left;
        Btree RIGHTp = tmp->right;
        //If the operator is found,solve left subtree
        if(LEFTp)
        {
            if(isOperator(LEFTp->data))
                num1 = solve(LEFTp);
            else
                num1 = LEFTp->data;
        }
        if(RIGHTp)
        {
            if(isOperator(RIGHTp->data))
            {
                num2 = solve(RIGHTp);
            }
            else
            {
                num2 = RIGHTp->data;
            }
        }
        operator = tmp->data;
        result = cal(operator, num1-'0',num2-'0');
        printf("%d\n",result);
        tmp->data =(result+'0');
        return root->data;
    }
return NULL;
}

void ConvertInPost(char infix[],char postfix[])
{
    int cnt=0;
    //while((expr[count++]=getchar())!='\n');
    //expr[--count] = '\0';
    int postCnt=0;
    char elem;
    while(cnt<strlen(infix))
    {
        elem = infix[cnt];
        if(elem=='(')
        {
            push(elem);
            cnt++;
            continue;
        }
        if (elem == ')')
		{
			while (top!=-1 && peek() != '(')
			{
				postfix[postCnt++] = peek();
				pop();
			}
			if (top!=-1)
			{
				pop();
			}
			cnt++;
			continue;
		}
        if (getPriority(elem) == 0)
		{
			postfix[postCnt++] = elem;
		}
		else
		{
			if (top==-1)
			{
				push(elem);
			}
			else
			{
				while (top!=-1 && peek() != '(' &&
					getPriority(elem) <= getPriority(peek()))
				{
					postfix[postCnt++] = peek();
					pop();
				}
				push(elem);
			}
		}
		cnt++;
	}

	while (top!=-1)
	{
		postfix[postCnt++] = peek();
		pop();
	}
	postfix[postCnt] = '\0';
}
/*
ExpTree build_exp_tree(ExpTree root,char expr[])
{
    int i=0;
    typedef struct Node *t1,*t2;
    while (expr[i] != '\0')
	{
		if (!(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^'))
		{
			root = node(expr[i]);
			push(root);
		}
		else
		{
			root = node(expr[i]);
			t1 = peek();
            pop();
			t2 = peek(); 
            pop();
			root->left = t1;
			root->right = t2;
			push(root);
		}
		i++;
	}
	return root;
}

*/

/*
void preOrder()
{
    if(root==NULL)
        return;
    //Print the value of root node
    printf("%d ",root->data);
    //Traverse to left subtree
    preOrder(root->left);
    //Traverse to right subtree
    preOrder(root->right);
}
*/

bool isValidChar(char s)
{
	if(isDigit(s) || isOperator(s))
	   return true;
	return false;
}

int main()
{
   // s->top=-1;
   
    char infix[100],expr[100];
    scanf("%s",infix);
    char  *postfix = (char *)malloc(sizeof(char) * strlen(infix));
    ConvertInPost(infix,postfix);
    
 /*   expr[0]= '('; 
   	
   	int i = 0;
   	while(i<strlen(infix))	
	{
   		if(isValidChar(infix[i]))
		{
   			expr[i+1]=expr[i]; 
		}
		else
		{
	    	printf("Invalid");	
			return 0;		
		} 
		i++; 	
	}
     	
   	expr[i+1]=')'; 
   	*/
   	
    

    int count=0;
   while((postfix[count++]=getchar())!='\n');
    postfix[--count] = '\0';
    //puts(expression);
int num;
   for(count = 0;postfix[count]!='\0';count++)
    {
        switch(postfix[count])
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '%':
            case '$':
                operatorFunc(postfix[count]);
                break;
                default:
                       num= postfix[count]-'0';
                        while ((postfix[count]='\n' && isDigit(postfix[count]))) 
                            num= num*10+(postfix[count]-'0');
                        operandFunc(num);
                        ungetc(postfix[count],stdin);  
                        break;
        }
    }
        printf("\n%d",solve(stack[top])-'0');
        return 0;
}
