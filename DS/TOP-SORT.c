#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int V[MAX]={0};
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
    printf("inserting : %d",node);
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

    // memset(V,0,sizeof(V));

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
