#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Node structure for adjacency list
struct Node{
    int data;
    struct Node* next;
};

// Graph structure
struct Graph{
    int numNodes;
    struct Node* adjList[MAX_NODES];
};

// Function to create a new node
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest){
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to perform Depth First Search (DFS)
int DFS(struct Graph* graph, int src, int dest, int visited[]){
    if (src == dest){
        return 1; // Destination node found
    }

    visited[src] = 1; // Mark the current node as visited

    struct Node* current = graph->adjList[src];

    while (current != NULL){
        if (!visited[current->data]){
            // Recursively call DFS for unvisited adjacent nodes
            if (DFS(graph, current->data, dest, visited))
                return 1; // If a path is found, return 1
        }
        current = current->next; // Move to the next adjacent node
    }

    return 0; // If destination node is not found
}


int main(){
    struct Graph graph;
    int numNodes, numEdges, src, dest;

    // Input number of nodes and edges
    scanf("%d %d", &numNodes, &numEdges);

    // Initialize graph
    graph.numNodes = numNodes;
    for (int i = 0; i < MAX_NODES; i++){
        graph.adjList[i] = NULL;
    }

    // Input edges
    for (int i = 0; i < numEdges; i++){
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    // Input source and destination nodes
    scanf("%d %d", &src, &dest);

    // Perform DFS
    int visited[MAX_NODES]= {0};
    if (DFS(&graph, src, dest, visited)){
        printf("There is a path from node %d to node %d.\n", src, dest);
    } else {
        printf("There is no path from node %d to node %d.\n", src, dest);
    }

    return 0;
}