//C program of Kruskal's using Union Find
#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define V 7

int E;
int adjM[V][V],parent[V];

int Find(int i)
{
    while(parent[i]!=i)
        i=parent[i];
    return i;
}

void Union(int i,int j)
{
    int a = Find(i);
    int b = Find(j);
    parent[a] = b;
}

void  Kruskal(int adjM[][V])
{
    int mincost = 0,cnt=0;
    for(int i=0;i<V;i++)
        parent[i]=i;

    while(cnt<V-1)
    {
        int min = INF,a=-1,b=-1;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(Find(i)!=Find(j)  && adjM[i][j]<min)
                {
                    min = adjM[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        Union(a, b);
        cnt++;
        mincost += min;
    }
 printf("\n Minimum cost= %d \n", mincost);
}

int main()
{
    printf("Enter the no of edges\n");
    scanf("%d",&E);

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(i==j)
                adjM[i][j]=0;
            else
                adjM[i][j]=INF;
        }
    }
    int u,v,w;
    for(int i=0;i<E;i++)
    {
       // printf("Enter the src,dest,weight");
        scanf("%d %d %d",&u,&v,&w);

        adjM[u][v]=w;
        adjM[v][u]=w;
    }
    Kruskal(adjM);

return 0;
}
