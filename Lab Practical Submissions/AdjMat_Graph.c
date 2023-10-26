#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the adjacency list
struct Graph {
    int V;             // Number of vertices
    struct Node** array;
};

// Create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++) {
        graph->array[i] = NULL;
    }

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

// Delete an edge from the graph
void deleteEdge(struct Graph* graph, int src, int dest) {
    // Delete the edge from src to dest
    struct Node* current = graph->array[src];
    struct Node* prev = NULL;

    while (current != NULL && current->vertex != dest) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            graph->array[src] = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
    }

    // Delete the edge from dest to src
    current = graph->array[dest];
    prev = NULL;

    while (current != NULL && current->vertex != src) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            graph->array[dest] = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
    }
}

// Print the adjacency list
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* current = graph->array[i];
        printf("Adjacency list of vertex %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Initial Graph:\n");
    printGraph(graph);

    deleteEdge(graph, 0, 1);
    deleteEdge(graph, 2, 3);

    printf("Graph after deleting edges:\n");
    printGraph(graph);

    return 0;
}
