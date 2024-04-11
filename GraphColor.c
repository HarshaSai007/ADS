#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices, numColors;
int colors[MAX_VERTICES];

bool isSafe(int vertex, int color) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && color == colors[i])
            return false;
    }
    return true;
}

bool graphColoring(int vertex) {
    if (vertex == numVertices)
        return true;

    for (int color = 1; color <= numColors; color++) {
        if (isSafe(vertex, color)) {
            colors[vertex] = color;
            if (graphColoring(vertex + 1))
                return true;
            colors[vertex] = 0;
        }
    }

    return false;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    if (graphColoring(0))
        printf("Graph coloring successful!\n");
    else
        printf("Graph coloring failed.\n");

    return 0;
}

