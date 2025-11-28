#include <stdio.h>

#define MAX 100

void DFS(int n, int graph[n][n], int visited[], int source) {
    int stack[MAX];
    int top = -1;

    // Push source
    stack[++top] = source;
    visited[source] = 1;

    while (top != -1) {
        // Pop from stack
        int node = stack[top--];
        printf("%d ", node);

        for (int i = n - 1; i >= 0; i--) {
            if (graph[node][i] != 0 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int visited[MAX]={0};

    int A[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }

    int source;
    printf("Enter starting node: ");
    scanf("%d", &source);

    printf("DFS (using stack) -> ");
    DFS(n, A, visited, source);
    printf("\n");
 
    return 0;
}
