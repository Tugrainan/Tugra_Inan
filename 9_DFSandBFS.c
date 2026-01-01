#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

// DFS Function (Recursive)
void DFS(int graph[V][V], int visited[], int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

// BFS Function (Using a simple Queue)
void BFS(int graph[V][V], int start) {
    int visited[V] = {0};
    int queue[V], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < V; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    // Adjacency Matrix representation
    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    int visitedDFS[V] = {0};

    printf("DFS Traversal: ");
    DFS(graph, visitedDFS, 0); // Expected: 0 1 3 2 4

    printf("\nBFS Traversal: ");
    BFS(graph, 0);             // Expected: 0 1 2 3 4

    return 0;
}
