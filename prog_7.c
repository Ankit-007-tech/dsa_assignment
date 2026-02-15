#include <stdio.h>
#include <limits.h>

#define MAX 20

int minDistance(int dist[], int visited[], int n)
{
    int min = INT_MAX, minIndex = -1;
    for(int i = 0; i < n; i++)
        if(!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    return minIndex;
}

void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int dist[MAX];
    int visited[MAX] = {0};

    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    for(int count = 0; count < n-1; count++)
    {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printf("Shortest distances from node %d:\n", source);
    for(int i = 0; i < n; i++)
        printf("To node %d: %d\n", i, dist[i]);
}

int main()
{
    int n, source;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix (0 if no edge):\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source node: ");
    scanf("%d", &source);

    dijkstra(graph, n, source);

    return 0;
}