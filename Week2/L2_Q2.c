//C-progam to implement singly linked list
//For performing insertion,deletion,reverse, linear search display

#include<stdio.h>
#include<stdlib.h>

//Create a structure of Node
struct Node
{
    int data;
    struct Node * next;
};

//Create a new node as head 
//Initially head is set to NULL,
struct Node *head=NULL;

//Insertion at first node,last node
void insertion(int x)
{
    printf("1. Insert at front\n,2. Insert at end\n");
    printf("Enter the choice:%t");
    int op;
    scanf("%d",&op);
    
    //Create a new node tmp and allocate memory to tmp
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node *));
    
    //If the choice is 1.Insert at front
    if(op==1)
    {
        //case 1:
        //Insert data into tmp node
            tmp->data = x;
            //If the initial node is head it is empty list
            if(tmp == NULL)
                printf("Empty list\n");
            
            else
            {	
            //Insert data into tmp 
            //copy address of head to link of tmp
            //Address of head is updated
                tmp->data=x;
                tmp->next=head;
                head=tmp;
            }
    }
    else if(op==2)
    {
       //case 2:If the choice is 1.Insert at end
       //Create a new node as last and allocate memory to last node
            struct Node *last = (struct Node *)malloc(sizeof(struct Node *));
            //Insert data into last node and set the link to NULL
            last->data =  x;
            last->next = NULL;
			
			//If the list is empty
			//Insert on the last node
			//Address of head is updated
            if(head==NULL)
                head=last;
                  
            else
            {
                //Creates a temp node and sets it to head
               struct Node * tmp = (struct Node *)malloc(sizeof(struct Node *));
               tmp = head;
	
			 //Scan the list and if null is found, add node to that prev node 
			 //Update link of tmp   
                while (tmp->next != NULL) 
                    tmp = tmp->next;

        // Appends the last node with last
            tmp->next = last;
            }
    }
}

//struct Node *insertatN(in
 

//Deletion at first node, last node
void deletion()
{
    printf("1.Delete at front\n,2. Delete  at end\n");
    printf("Enter the choice:%t");
    int op;
    scanf("%d",&op);
    //Create new node as tmp and allocate memory
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node *));
    if(op==1)
    {
    //Copy the address of head to tmp
    //Update head with link of head 
    //Free tmp memory
        tmp = head;
        head = head->next;
        free(tmp);
    }
    else if(op==2)
    {
        tmp = head;
        struct Node *t2 = (struct Node *)malloc(sizeof(struct Node *));
        
        //Scan the list till NULL link is reached
        //Copy address of tmp with t2
        //Update the tmp and set t2 to NULL
        while(tmp->next!=NULL)
        {
            t2=tmp;
            tmp =tmp->next;
        }
        free(t2->next);
        t2->next=NULL;
    }
}

void search(int x, int n)
{
    struct Node * tmp;
    int i=0, flag;
    tmp=head;
    if(head==NULL)
        printf("Empty List\n");
    else
    {
         while (tmp!=NULL)
        {
            //If element is present in the list
            if(tmp->data == x)  
            {
                printf("Element found at location:%d \n",(i+1)); 
                flag=0; 
            } 
            else  
                flag++; 
            i++; 
            tmp = tmp -> next;
        }       
    }
}

//Function to display status of linked list
void display() 
{

    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node *));
    if(head == NULL)
        printf("Empty list");
    else
    {
    	//storing  of 1st node into tmp
        tmp = head;
        printf("Linked List: ");
        //Display of linked list 
        while(tmp != NULL)
        {
            printf("%d->",tmp->data);
            tmp = tmp->next;
        }
        //Print Link of last node
        if(tmp==NULL)
            printf("NULL");
    }
}

//Function to reverse linked list element
void reverse()
{
    struct Node *prev = NULL;
    struct Node *next = NULL;
    struct Node *cur=head;
    
    while(cur!=NULL)
    {
        //Store address of current next into next
        next=cur->next;

        //Reverse current node's pointer
        cur->next=prev;

		//Update prev with cur
        prev=cur;
        //Update cur with next
        cur=next;
    }
    //Update head with prev
    head=prev;
}

int main()
{
    printf("Enter the no of elements");
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter the element");
        int elem;
        scanf("%d",&elem);
        insertion(elem);
        display();
	//    int pos;
 	//   scanf("%d",&pos);
    }
        //InsertNth(45,2);
        //display();
        int x;
        printf("Enter the element to be search ");
        scanf("%d",&x);
        search(x,n);
        deletion();
        display();
		
		printf("\n");
        reverse();
        printf("Reversed ");
        display();
        
        free(head);
        return 0;
}
