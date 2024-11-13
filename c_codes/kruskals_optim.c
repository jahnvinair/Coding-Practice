#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX], rank[MAX];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void union1(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

void kruskal(int n, Edge edges[], int edge_count) {
    int mincost = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    qsort(edges, edge_count, sizeof(Edge), compareEdges);

    for (int i = 0; i < edge_count; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            union1(u, v);
            printf("Edge %d:(%d, %d) cost:%d\n", i, u, v, w);
            mincost += w;
        }
    }
    printf("Minimum cost = %d\n", mincost);
}

int main() {
    int n, edge_count = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    Edge edges[MAX * MAX];
    int cost[MAX][MAX];
    
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] != 0 && i < j) {
                edges[edge_count].u = i;
                edges[edge_count].v = j;
                edges[edge_count].w = cost[i][j];
                edge_count++;
            }
        }
    }

    kruskal(n, edges, edge_count);
    return 0;
}
