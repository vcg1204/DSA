#include <stdio.h>
#include <stdbool.h>
#define MAX 100

void DFS(int graph[MAX][MAX], int startVertex, int n)
{
    bool visited[MAX];
    int stack[MAX];
    int top = -1;

    // Initialize all vertices as not visited
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // Push the start vertex onto the stack and mark it as visited
    stack[++top] = startVertex;
    visited[startVertex] = true;

    while (top != -1)
    {
        // Pop a vertex from the stack and print it
        int vertex = stack[top--];
        printf("%d ", vertex);

        // Check all adjacent vertices in reverse order
        // (to maintain the DFS order when using a stack)
        for (int i = n - 1; i >= 0; i--)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                stack[++top] = i; // Push unvisited adjacent vertex onto the stack
                visited[i] = true;
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

    printf("DFS traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex, n);

    return 0;
}
