#include <stdio.h>
#include <limits.h>

#define V 6
#define INF INT_MAX

//Function to return min value 
int min(int a,int b)
{
    return (a<b)?a:b;
}

//Function to print adjacency Matrix
void printMatrix(int graph[V][V])
{
        for (int i = 1; i <= V; i++) 
        {
            for (int j = 1; j <= V; j++) 
            {
                if (graph[i][j] == INF)
                    printf("%4s","INF");
                else
                    printf("%4d", graph[i][j]);
            }
            printf("\n");
        }
}

void Floyd_Warshall(int graph[V][V])
{
    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
            //All diagonal element is set to zero
                if(i==j)
                    graph[i][j]=0;
              //To handle INF, each distance of graph compared with INF and min of distance is calculated
                else if(graph[i][k]!=INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
        //To print the matrix at each iteration
        printf("Iteration %d\n",k);
        printMatrix(graph);
        printf("\n");
    }
}


int main()
{
    int E;
    printf("Enter the no of edges\n");
    scanf("%d",&E);

    int adjM[V][V];
    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            if(i==j)
                adjM[i][j]=0;
            else
                adjM[i][j]=INF;
        }
    }

    int u,v,w;
    for(int i=1;i<=E;i++)
    {
//        printf("Enter the src,dest,weight");
        scanf("%d %d %d",&u,&v,&w);

        adjM[u][v]=w;
        adjM[v][u]=w;
    }
    printf("Original Distance Matrix\n");
    printMatrix(adjM);
    Floyd_Warshall(adjM);
    printf("Final Distance matrix\n");
    printMatrix(adjM);

    return 0;
}



