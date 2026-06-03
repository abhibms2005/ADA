#include<stdio.h>
#define max 10
#define inf 999

int parent[max];

int find(int i){
    while(parent[i] != -1){
        i = parent[i];
    }
    return i;
}

void union_set(int u, int v){
    parent[v] = u;
}

int main(){
    int n;
    int cost[max][max];
    int min;
    int a,b,u,v;
    int mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        parent[i] = -1;
    }

    printf("Enter cost matrix:\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0)
                cost[i][j]=inf;
        }
    }

    printf("Edges in MST:\n");

    int edge_count=0;

    while(edge_count < n-1){

        min = inf;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(u != v){
            printf("Edge %d : (%d -> %d) Cost = %d\n",
                   edge_count+1,a,b,min);

            mincost += min;
            union_set(u,v);
            edge_count++;
        }

        cost[a][b] = cost[b][a] = inf;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}