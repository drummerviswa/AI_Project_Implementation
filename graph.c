#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

graph_t *createGraph(int nodes) {
    graph_t *g = (graph_t *)malloc(sizeof(graph_t));
    g->nodes = nodes;
    
    g->matrix = (int **)malloc(nodes * sizeof(int *));
    for (int i = 0; i < nodes; i++) {
        g->matrix[i] = (int *)calloc(nodes, sizeof(int));
    }

    return g;
}
void addEdge(graph_t *g, int src, int dest, int weight) {
    if (src >= 0 && src < g->nodes && dest >= 0 && dest < g->nodes) {
        g->matrix[src][dest] = weight;
    }
}

int getEdge(graph_t *g, int src, int dest) {
    if (src >= 0 && src < g->nodes && dest >= 0 && dest < g->nodes) {
        return g->matrix[src][dest];
    }
    return 0;
}

void destroyGraph(graph_t *g) {
    for (int i = 0; i < g->nodes; i++) {
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g);
}


void displayGraph(graph_t *g) {
    printf("Graph\n");
    for (int i = 0; i < g->nodes; i++) {
        for (int j = 0; j < g->nodes; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}