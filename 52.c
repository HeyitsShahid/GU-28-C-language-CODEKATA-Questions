//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for adjacency list node
typedef struct AdjListNode {
    int vertex;
    struct AdjListNode* next;
} AdjListNode;

// Structure for adjacency list
typedef struct {
    AdjListNode* head;
    int vertex_count;  // Number of adjacent vertices
} AdjList;

// Structure for the graph
typedef struct {
    AdjList* array;
    int vertex_capacity;  // Current capacity for vertices
    int vertex_count;     // Number of vertices currently in graph
} Graph;

// Create a new adjacency list node
AdjListNode* createNode(int vertex) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    if (!newNode) return NULL;
    
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
Graph* createGraph(int initial_capacity) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) return NULL;
    
    graph->array = (AdjList*)calloc(initial_capacity, sizeof(AdjList));
    if (!graph->array) {
        free(graph);
        return NULL;
    }
    
    graph->vertex_capacity = initial_capacity;
    graph->vertex_count = 0;
    
    // Initialize adjacency lists
    for (int i = 0; i < initial_capacity; i++) {
        graph->array[i].head = NULL;
        graph->array[i].vertex_count = 0;
    }
    
    return graph;
}

// Resize graph to accommodate more vertices
int resizeGraph(Graph* graph, int new_capacity) {
    AdjList* new_array = (AdjList*)realloc(graph->array, new_capacity * sizeof(AdjList));
    if (!new_array) return 0;
    
    graph->array = new_array;
    
    // Initialize new adjacency lists
    for (int i = graph->vertex_capacity; i < new_capacity; i++) {
        graph->array[i].head = NULL;
        graph->array[i].vertex_count = 0;
    }
    
    graph->vertex_capacity = new_capacity;
    return 1;
}

// Add a new vertex to the graph
int addVertex(Graph* graph, int vertex) {
    if (!graph) return 0;
    
    // Check if vertex is within current capacity
    if (vertex >= graph->vertex_capacity) {
        // Resize to double the required capacity
        int new_capacity = (vertex + 1) * 2;
        if (!resizeGraph(graph, new_capacity)) return 0;
    }
    
    // Update vertex count if this is a new maximum vertex
    if (vertex >= graph->vertex_count) {
        graph->vertex_count = vertex + 1;
    }
    
    return 1;
}

// Check if an edge exists
int edgeExists(Graph* graph, int src, int dest) {
    AdjListNode* current = graph->array[src].head;
    while (current) {
        if (current->vertex == dest) return 1;
        current = current->next;
    }
    return 0;
}

// Add an edge to the graph
int addEdge(Graph* graph, int src, int dest) {
    if (!graph || src < 0 || dest < 0) return 0;
    
    // Ensure both vertices exist
    if (!addVertex(graph, src) || !addVertex(graph, dest)) return 0;
    
    // Check if edge already exists
    if (edgeExists(graph, src, dest)) return 1;
    
    // Add edge from src to dest
    AdjListNode* newNode = createNode(dest);
    if (!newNode) return 0;
    
    // Add at beginning of adjacency list
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    graph->array[src].vertex_count++;
    
    return 1;
}

// Print adjacency list for a specific vertex
void printVertexAdjList(Graph* graph, int vertex) {
    if (!graph || vertex >= graph->vertex_count) return;
    
    printf("%d: [", vertex);
    
    AdjListNode* current = graph->array[vertex].head;
    while (current) {
        printf("%d", current->vertex);
        current = current->next;
        if (current) printf(", ");
    }
    printf("]\n");
}

// Print entire graph's adjacency lists
void printGraph(Graph* graph) {
    if (!graph) return;
    
    for (int i = 0; i < graph->vertex_count; i++) {
        if (graph->array[i].vertex_count > 0) {  // Only print vertices with edges
            printVertexAdjList(graph, i);
        }
    }
}

// Free graph memory
void freeGraph(Graph* graph) {
    if (!graph) return;
    
    // Free all adjacency lists
    for (int i = 0; i < graph->vertex_capacity; i++) {
        AdjListNode* current = graph->array[i].head;
        while (current) {
            AdjListNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    free(graph->array);
    free(graph);
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Create graph with initial capacity
    Graph* graph = createGraph(10);
    if (!graph) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    char operation[15];
    int v1, v2;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", operation);
        
        if (strcmp(operation, "ADD_VERTEX") == 0) {
            scanf("%d", &v1);
            addVertex(graph, v1);
        }
        else if (strcmp(operation, "ADD_EDGE") == 0) {
            scanf("%d %d", &v1, &v2);
            addEdge(graph, v1, v2);
        }
        else if (strcmp(operation, "PRINT_ADJ_LIST") == 0) {
            printGraph(graph);
        }
    }
    
    freeGraph(graph);
    return 0;
}
