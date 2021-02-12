#include<stdio.h>
#include<stdlib.h>
int V;
int adj[10][10];
int queue[10]={0};
int front =1,rear=0,visited[10]={0};

void BFS(int u)
{
    visited[u]=1;
    printf("%d ",u);
    for(int i=1;i<=V;i++)
        if(adj[u][i] && !visited[i])
            queue[++rear]=i;
        if(front<=rear)
            BFS(queue[front++]);
    
}

void initialize()
{
    int u,v;
    for(int i=1;i<=V;i++)
        for(int j=1;j<=V;j++)
            adj[i][j]=0;
}
int main()
{
    initialize();
    printf("Enter the no of vertices");
    scanf("%d",&V);
    int E;
    printf("Enter the no of edges");
    scanf("%d",&E);
    for(int i=1;i<=E;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int stv;
    scanf("%d",&stv);
    BFS(stv);
   /*     
    for(int i=0; i <= V; i++) 
    {
        if(visited[i])
            printf("%d\t", i);
        else 
            break;
        
    }
    */
    printf("\n");
return 0;
}
