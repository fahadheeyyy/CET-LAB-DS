#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

// Correct DFS for cycle detection in UNDIRECTED GRAPHS
int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] != 0) {   // if edge exists
            if (!visited[i]) {
                if (DFS(i, n, graph, visited, node))
                    return 1;        // cycle found deeper
            }
            else if (i != parent) {
                return 1;            // visited but not parent → cycle
            }
        }
    }
    return 0;  // no cycle
}

int main() 
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Read adjacency matrix
    int A[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("enter [%d][%d] : ", i, j);
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0)
                A[i][j] = INT_MAX;   // treat 0 as no edge
        }
    }

    int mst[MAX_NODES][MAX_NODES] = {0};
    int edge_count = 0, cost = 0;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edge_count < n - 1) {

        // Step 1: Find the minimum edge
        int min = INT_MAX, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] < min) {
                    min = A[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (min == INT_MAX) break;  // no more edges → disconnected graph

        // Step 2: Tentatively add this edge to MST
        mst[u][v] = min;

        // Remove it from A so it is not chosen again
        A[u][v] = INT_MAX;

        // Step 3: Cycle check using DFS
        int visited[MAX_NODES] = {0};

        if (DFS(u, n, mst, visited, -1)) {
            // cycle found → remove edge
            mst[u][v] = 0;
        }
        else {
            // no cycle → accept edge
            cost += min;
            printf("{%d, %d} = %d\n", u, v, min);
            edge_count++;
        }
    }

    printf("\nMinimum Cost: %d\n", cost);

    return 0;
}