#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];  // adjacency matrix
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Function to add element to queue
void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

// Function to remove element from queue
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS function
void bfs(int start, int n) {
    int i, current;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front <= rear) {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, edges, i, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
 

    // Initialize adjacency matrix and visited array
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(start, n);

    return 0;
}
