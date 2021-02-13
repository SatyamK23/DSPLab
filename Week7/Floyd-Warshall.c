#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

//Function to print adjacency Matrix
void printMatrix(int V, int (*graph)[V])
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

void Floyd_Warshall(int V,int (*graph)[V])
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
        printMatrix(V, graph);
        printf("\n");
    }
}


int main()
{
    int V,E;
    printf("Enter the no of vertices,edges\n");
    scanf("%d %d",&V,&E);

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

	//For directed edge set edge from u to v to w
	//For undirected edge uncomment adjM[v][u]
        adjM[u][v]=w;
       // adjM[v][u]=w;
    }
    printf("Original Distance Matrix\n");
    printMatrix(V,adjM);
    Floyd_Warshall(V, adjM);
    printf("Final Distance matrix\n");
    printMatrix(V, adjM);

    return 0;
}



