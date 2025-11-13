#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = -1;

// Function to enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Function to dequeue
int dequeue() {
    return queue[front++];
}

int main() {
    int n, e;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];
    int indegree[n];

    // Initialize graph with 0
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            graph[i][j] = 0;
        }
        indegree[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) meaning u -> v:\n");
    for(i = 0; i < e; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        indegree[v]++;   // Increase indegree of destination vertex
    }

    // Enqueue all vertices with indegree 0
    for(i = 0; i < n; i++){
        if(indegree[i] == 0){
            enqueue(i);
        }
    }

    int count = 0;
    int topo[n];

    while(front <= rear){
        int node = dequeue();
        topo[count++] = node;

        // Reduce indegree of neighbors
        for(j = 0; j < n; j++){
            if(graph[node][j] == 1){
                indegree[j]--;

                // If indegree becomes 0, add to queue
                if(indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    // If count != n, graph has a cycle
    if(count != n){
        printf("Graph has a cycle. Topological sort not possible.\n");
    }
    else {
        printf("Topological order: ");
        for(i = 0; i < n; i++){
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}
