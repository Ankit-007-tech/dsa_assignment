# Undirected Graph Using Adjacency Matrix with BFS and DFS

## Data Structure

The program represents an undirected graph using an **adjacency matrix**.  
- `adjMatrix[i][j] = 1` → edge exists between vertex `i` and `j`  
- `adjMatrix[i][j] = 0` → no edge  
- `visited[]` tracks whether a vertex has been visited during traversal  
- BFS uses a queue; DFS uses recursion  

## Functions

enqueue(node) → Adds a node to the BFS queue  
dequeue() → Removes a node from the BFS queue  
isEmpty() → Checks if BFS queue is empty  

BFS(start, n) → Traverses the graph in **Breadth-First Search** order starting from a given node  

DFS(start, n) → Traverses the graph in **Depth-First Search** order starting from a given node using recursion  

DFSUtil(node, n) → Recursive helper for DFS  

## Main Function

- Takes number of vertices and edges as input  
- Takes all edges as input to populate the adjacency matrix  
- Performs BFS starting from vertex 0  
- Performs DFS starting from vertex 0  

## Complete Program

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX], front = 0, rear = -1;

void enqueue(int node){ queue[++rear] = node; }
int dequeue(){ return queue[front++]; }
int isEmpty(){ return front > rear; }

void BFS(int start, int n)
{
    for(int i = 0; i < n; i++) visited[i] = 0;
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
        if(adjMatrix[node][i] && !visited[i])
            DFSUtil(i, n);
}

void DFS(int start, int n)
{
    for(int i = 0; i < n; i++) visited[i] = 0;
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

## Sample Output

Enter number of vertices: 5  
Enter number of edges: 6  
Enter edge 1 (u v): 0 1  
Enter edge 2 (u v): 0 2  
Enter edge 3 (u v): 1 2  
Enter edge 4 (u v): 1 3  
Enter edge 5 (u v): 2 4  
Enter edge 6 (u v): 3 4  

BFS traversal starting from vertex 0: 0 1 2 3 4  
DFS traversal starting from vertex 0: 0 1 2 4 3  

## Conclusion

This program demonstrates how to represent an undirected graph using an adjacency matrix and traverse it using BFS and DFS.  
It allows easy input of vertices and edges and shows both traversal orders starting from vertex 0.