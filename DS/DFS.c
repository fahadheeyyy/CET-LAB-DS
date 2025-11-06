#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];  // adjacency matrix
int visited[MAX];
int stack[MAX];
int top = -1;

// Function to push element onto stack
void push(int vertex) {
    if (top == MAX - 1) return;
    stack[++top] = vertex;
}

// Function to pop element from stack
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// DFS function
void dfs(int start, int n) {
    int i, current;
    push(start);
    visited[start] = 1;

    printf("DFS Traversal: ");
    while (top != -1) {
        current = pop();
        printf("%d ", current);

        for (i = 1; i <= n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                push(i);
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

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    dfs(start, n);

    return 0;
}
