#include <stdio.h>

#define INF 99999  // A large value representing infinity (no path)

void floydWarshall(int graph[][4], int n) {
    int dist[n][n];
    
    // Initialize the solution matrix same as the input graph matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Update dist[i][j] if a shorter path is found through vertex k
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example graph with 4 vertices
    int graph[4][4] = { {0, 3, INF, 7},
                        {8, 0, 2, INF},
                        {5, INF, 0, 1},
                        {2, INF, INF, 0} };
    
    int n = 4;  // Number of vertices
    
    floydWarshall(graph, n);
    
    return 0;
}
