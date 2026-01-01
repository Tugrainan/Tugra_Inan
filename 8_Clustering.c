#include <stdio.h>

#define V 5 // Number of nodes (vertices)

// DFS function to visit all nodes in one cluster
void findCluster(int matrix[V][V], int visited[], int node) {
    visited[node] = 1; // Mark current node as visited

    for (int i = 0; i < V; i++) {
        // If there is a connection and the neighbor is not visited
        if (matrix[node][i] == 1 && !visited[i]) {
            findCluster(matrix, visited, i);
        }
    }
}

int main() {
    // Adjacency Matrix (1 = connected, 0 = not connected)
    int graph[V][V] = {
        {1, 1, 0, 0, 0}, // Cluster 1: Node 0 and 1
        {1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0}, // Cluster 2: Node 2 and 3
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1}  // Cluster 3: Node 4 is alone
    };

    int visited[V] = {0}; // Track visited nodes
    int clusterCount = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Found Cluster %d starting at node %d\n", clusterCount, i);
            findCluster(graph, visited, i);
        }
    }

    printf("\nTotal number of clusters: %d\n", clusterCount);

    return 0;
}
