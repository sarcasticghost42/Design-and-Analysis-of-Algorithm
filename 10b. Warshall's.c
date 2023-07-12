#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void createGraph(int adj[MAX][MAX], int n)
{
    printf("Enter Adj Matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
}

void warshlAlgo(int adj[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                adj[j][k] = adj[j][k] || (adj[j][i] && adj[i][k]);
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
    warshlAlgo(adj, n);
    printGraph(adj, n);

    return 0;
}
