// #include <stdio.h>
// #include <string.h>

// #define MAX_NODES 100

// int A[MAX_NODES][MAX_NODES]; // adjacency matrix
// int visited[MAX_NODES];
// int stack[MAX_NODES];
// int top = -1;

// void dfs(int node, int n) {
//     visited[node] = 1;

//     // Explore all outgoing edges: node → j
//     for (int j = 0; j < n; j++) {
//         if (A[node][j] == 1 && !visited[j]) {
//             dfs(j, n);
//         }
//     }

//     // Push to stack *after* exploring neighbors
//     stack[++top] = node;
// }

// int main() {
//     int n;
//     printf("Enter the number of nodes: ");
//     scanf("%d", &n);

//     // Input adjacency matrix
//     printf("\nEnter adjacency matrix (0/1):\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("A[%d][%d]: ", i, j);
//             scanf("%d", &A[i][j]);
//         }
//     }

//     memset(visited, 0, sizeof(visited));

//     // Perform DFS Topological Sort
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {
//             dfs(i, n);
//         }
//     }

//     printf("\nTopological Order:\n");
//     while (top != -1) {
//         printf("%d ", stack[top--]);  // print in reverse finish time
//     }
//     printf("\n");

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int V[MAX];
int stack[MAX];
int adj[MAX][MAX];
int top=-1;

void dfs(int node,int n){
    V[node]=1;

    for (int j =0;j<n;j++){
        if(adj[node][j]==1 && !V[j]){
            dfs(j,n);
        }
    }

    stack[++top]=node;
}

int main(){

    int n;
    printf("enter size :");
    scanf("%d",&n);

    // int adj[n][n];

    for(int i =0; i<n;i++){
        for(int j =0; j<n ; j++){
            printf("[%i][%d] :",i,j);
            scanf("%d",&adj[i][j]);
        }
    }

    memset(V,0,sizeof(V));

    for (int i=0 ; i<n ; i++){
        if (!V[i]){
            dfs(i,n);
        }
    }

    printf("sorting:");

    while(top!=-1){
        printf("%d" , stack[top--] );
    }

    return 0;
}
