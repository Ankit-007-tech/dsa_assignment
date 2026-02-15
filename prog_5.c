#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX], front = 0, rear = -1;

void enqueue(int node)
{
    queue[++rear] = node;
}

int dequeue()
{
    return queue[front++];
}

int isEmpty()
{
    return front > rear;
}

void BFS(int start, int n)
{
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while(!isEmpty())
    {
        int node = dequeue();
        printf("%d ", node);

        for(int i = 0; i < n; i++)
        {
            if(adjMatrix[node][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

void DFSUtil(int node, int n)
{
    visited[node] = 1;
    printf("%d ", node);

    for(int i = 0; i < n; i++)
    {
        if(adjMatrix[node][i] && !visited[i])
            DFSUtil(i, n);
    }
}

void DFS(int start, int n)
{
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    DFSUtil(start, n);
}

int main()
{
    int n, edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++)
    {
        printf("Enter edge %d (u v): ", i+1);
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    printf("\nBFS traversal starting from vertex 0: ");
    BFS(0, n);

    printf("\nDFS traversal starting from vertex 0: ");
    DFS(0, n);

    return 0;
}