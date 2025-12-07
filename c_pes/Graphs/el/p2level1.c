//
// Created by Kishi Kishore N on 07/12/25.
//

#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for graph
struct Graph {
    int V;
    struct Node** adjList;
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = vertices;

    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for(int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add dest to src list
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add src to dest list (because undirected)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Display the graph
void displayGraph(struct Graph* graph) {
    for(int v = 0; v < graph->V; v++) {
        struct Node* temp = graph->adjList[v];
        printf("%d -> ", v);
        while(temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int v, e, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Graph* graph = createGraph(v);

    printf("Enter the edges (source destination):\n");
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nAdjacency List:\n");
    displayGraph(graph);

    return 0;
}