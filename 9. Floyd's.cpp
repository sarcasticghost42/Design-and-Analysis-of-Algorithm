#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999
#define min(x,y) (((x)>(y) ? y: x))

void createGraph(int adj[MAX][MAX], int n)
{
    printf("Enter Adj Matrix: (999 for infinity)\n ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
}

void floyd(int adj[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }
}

void printGraph(int adj[MAX][MAX], int n)
{
    printf("After:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INF)
                printf("Infinity");
            else
                printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter No of Vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];

    createGraph(adj, n);
    floyd(adj, n);
    printGraph(adj, n);

    return 0;
}
