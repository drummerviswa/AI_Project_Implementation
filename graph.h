#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int nodes;
    int **matrix;
} graph_t;

graph_t *createGraph(int nodes);
void addEdge(graph_t *g, int src, int dest, int weight);
int getEdge(graph_t *g, int src, int dest);
void destroyGraph(graph_t *g);
void displayGraph(graph_t *g);

#endif
