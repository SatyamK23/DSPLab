#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

// A structure to represent an adjacency list node
typedef struct _Node
{
    int dest;
    struct _Node* next;
}Node;

/* This is the structure of the adjacency list
* It simply has an array of Nodes
*/
typedef struct _Adj
{
    Node *list;  // pointer to head node of list
}Adj;


// Prototypes
/*
* This function creates the edge between the two vertices.
 * Since we have an UNDIRECTED graph, when I create the edges, I create them for both       vertex and destination
  */
void addEdge(Adj* list, int src, int dest)
{
    //create the edge between vertex and destination
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = list[src].list;
    temp->dest = dest;
    list[src].list = temp;

    //create the edge between dest and vertex
    Node* temp2 = (Node*)malloc(sizeof(Node));
    temp2->next = list[dest].list;
    temp2->dest = src;
    list[dest].list = temp2;
}

//Run a DFS given the Adjacency list and vertex in the list
 void DFS(Adj* list, int V)
{
    visited[V] = 1;
    Node *temp;

    for(temp = list[V].list; temp != NULL; temp = temp->next)
    {   
        if(visited[temp->dest] == 0)
            DFS(list, temp->dest);
    }
 }

 FILE *fp; 
int main(int argc, char **argv)
 {
     int u,v,V,E;
     Node *head = NULL;

     int connected_components = 0;

     //make sure enough arguments are supplied
     if(argc<2)
     {
         printf("Filename must be provided as argument\n");
         exit(0);
     }

     //open the file
     fp = fopen(argv[1], "r");

     //check to see if the file was opened
     if(fp == NULL)
     {
         printf("The file could not be opened\n");
         exit(2);
     }

     //grab the first number. It is the number of vertices
     fscanf(fp, "%d %d", &V,&E);
     if(E<0)
     {
         printf("Graph is not possible\n");
         exit(0);
     }

     //Create the struct pointer and call the function to create the Graph
     Adj *list = (Adj *)malloc(sizeof(Adj)*(V+1));

     //run through each pair of numbers 
     while(fscanf(fp, "%d %d", &u, &v)!=EOF)
     {   
         // create the first list    
         addEdge(list,u, v);
     }

     Node *temp;
     //run through the graph's nodes
     for (int i= 1; i < (1+V); i++)
     {
         if(visited[i] == 0)
         {
             DFS(list, i);
             connected_components++;
         }
     }

     printf("The number of connected components is %d\n", connected_components);
     free(list);
     return 0;
}


