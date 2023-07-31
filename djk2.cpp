#include <iostream>
using namespace std;

void dijkstra(int n, int source, int cost[10][10], int distance[])
{
    int i, v, u, visited[10], min, count = 1;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    for (i = 0; i < n; i++)
        distance[i] = cost[source][i];
    visited[source] = 1;
    while (count <= n - 1)
    {
        min = 999;
        for (u = 0; u < n; u++)
        {
            if (distance[u] < min && !visited[u])
            {
                min = distance[u];
                v = u;
            }
        }
        visited[v] = 1;
        count++;
        for (u = 0; u < n; u++)
        {
            if ((distance[v] + cost[v][u] < distance[u]) && !visited[u])
            {
                distance[u] = distance[v] + cost[v][u];
            }
        }
    }
}

int main()
{
    int n, source, i, j, cost[10][10], distance[10];
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the cost matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    cout << "Enter the source: ";
    cin >> source;
    dijkstra(n, source, cost, distance);
    cout << "Shortest paths from the given source are:\n";
    for (i = 0; i < n; i++)
    {
        if (i != source)
        {
            cout << source << " --> " << i << " : cost = " << distance[i] << endl;
        }
    }
    return 0;
}

