#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent the graph
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    bool* visited;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    int i;
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (bool*)malloc(vertices * sizeof(bool));
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to implement BFS
void bfs(Graph* graph, int startVertex) {
    int queue[100];
    int front = 0, rear = 0;
    int currentVertex, adjVertex;
    Node* temp;

    graph->visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
	currentVertex = queue[front++];
	printf("%d ", currentVertex);

	temp = graph->adjLists[currentVertex];
        while (temp) {
	    adjVertex = temp->vertex;
	    if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int numVertices = 6;
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("BFS Traversal starting from vertex 0: ");
    bfs(graph, 0);
    printf("\n");

    printf("BFS 0: ");
    bfs(graph, 0);
    printf("\n");

    printf("BFS 0: ");
    bfs(graph, 0);
    printf("\n");

    return 0;
}

