#include<stdio.h>
#include<stdlib.h>

//Graph parameters
int V;
int adj[10][10];
int visited[10]={0};

//Stack parameters
int stack[10],top=-1;

void push(int u)
{
    if(top==9)
        return;
    stack[++top]=u;
}

int pop()
{
    int u;
    if(top==-1)
        exit(1);
    else
        return stack[top--];
}

int isEmpty()
{
    return (top==-1)?1:0;
}

void DFS(int u)
{
    push(u);
    while(!isEmpty())
    {
        u = pop();
        if(visited[u]==0)
        {
            printf("%d ",u);
            visited[u]=1;
        }
        for(int i=V;i>=1;i--)
        {
            if(!visited[i] && adj[u][i]==1)
                push(i);
        }
    }
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
    int E;
    printf("Enter the no of vertices");
    scanf("%d",&V);
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
    DFS(stv);

    printf("\n");
return 0;
}
