#include <stdio.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void initializeGraph(int vertices) {
    for (int i = 1; i <= vertices; i++) {
        visited[i] = 0;
        for (int j = 1; j <= vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(int from, int to) {
    adjacencyMatrix[from][to] = 1;
    adjacencyMatrix[to][from] = 1;
}

void depthFirstSearch(int vertex, int vertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 1; i <= vertices; i++) {
        if (adjacencyMatrix[vertex][i] && !visited[i]) {
            depthFirstSearch(i, vertices);
        }
    }
}

int main() {
    int vertices, choice, source;
    
    printf("ENTER THE NUMBER VERTICES: ");
    scanf("%d", &vertices);
    
    initializeGraph(vertices);

    printf("ENTER THE ADJACENCY MATRIX (0 or 1):\n");
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("THE ADJACENCY MATRIX IS:\n");
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    do {
        printf("\nMENU:\n");
        printf("1. Perform DFS\n");
        printf("2. Exit\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ENTER THE SOURCE VERTEX: ");
                scanf("%d", &source);
                printf("DFS TRAVERSAL: ");
                depthFirstSearch(source, vertices);
                printf("\n");
                break;
            case 2:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
