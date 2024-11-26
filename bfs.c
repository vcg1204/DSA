#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void BFS(int graph[MAX][MAX], int startVertex, int n)
{
    bool visited[MAX];
    int queue[MAX];
    int front = 0, rear = 0;

    // Initialize all vertices as not visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear)
    {
        // Dequeue the vertex and print it
        int vertex = queue[front++];
        printf("%d ", vertex);

        // Check all adjacent vertices
        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            { 
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS traversal starting from vertex %d: ", startVertex);
    BFS(graph, startVertex, n);

    return 0;
}