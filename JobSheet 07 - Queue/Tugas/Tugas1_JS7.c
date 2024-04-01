/*
    Nama  : Ridho Hamdani Putra
    Nim   : 23343052
    Prodi : Informatika
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Node dalam graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Representasi graph dengan list adjasensi
typedef struct Graph {
    int numNodes;
    Node* adjList[MAX_NODES];
} Graph;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk membuat graph baru
Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;

    // Inisialisasi list adjasensi
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Fungsi untuk menambahkan edge antara dua node
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Karena graph tak berarah, tambahkan edge dari dest ke src juga
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Fungsi untuk melakukan Breadth First Search
void BFS(Graph* graph, int startNode) {
    // Array untuk menandai node yang telah dikunjungi
    int visited[MAX_NODES] = {0};

    // Queue untuk menyimpan node yang akan dikunjungi selanjutnya
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    // Mulai dari node awal
    visited[startNode] = 1;
    queue[rear++] = startNode;

    // Selama queue tidak kosong, proses node secara BFS
    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        // Traverse melalui simpul-simpul bertetangga dari simpul saat ini
        Node* temp = graph->adjList[currentNode];
        while (temp != NULL) {
            int adjNode = temp->data;
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                queue[rear++] = adjNode;
            }
            temp = temp->next;
        }
    }
}

int main() {
    // Membuat graph
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Hasil dari BFS (mulai dari node 0): ");
    BFS(graph, 0);
    printf("\n");

    return 0;
}
