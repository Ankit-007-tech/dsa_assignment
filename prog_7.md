# Dijkstra’s Algorithm for Shortest Path in a Weighted Graph

## Data Structure

The program represents a **weighted graph** using an **adjacency matrix**:  
- `graph[i][j]` → weight of edge from vertex `i` to `j`  
- `graph[i][j] = 0` → no edge exists  
- `dist[]` stores the shortest distance from the source node to each vertex  
- `visited[]` tracks which nodes have been processed  

## Functions

minDistance(dist, visited, n) → Finds the unvisited node with the smallest distance value  

dijkstra(graph, n, source) → Computes shortest distances from the source node to all vertices using **Dijkstra’s algorithm**  

## Main Function

- Takes number of vertices and adjacency matrix as input  
- Takes the source node  
- Calls the Dijkstra function to compute shortest distances  
- Displays distances from the source to all nodes  

## Sample Input/Output

Enter number of vertices: 5  
Enter the adjacency matrix (0 if no edge):  
0 10 0 30 100  
10 0 50 0 0  
0 50 0 20 10  
30 0 20 0 60  
100 0 10 60 0  
Enter source node: 0  

Shortest distances from node 0:  
To node 0: 0  
To node 1: 10  
To node 2: 50  
To node 3: 30  
To node 4: 60  

## Conclusion

This program demonstrates how to implement **Dijkstra’s algorithm** using an adjacency matrix.  
It calculates the **shortest path from a source node** to all other nodes in a weighted graph efficiently.