#include <stdio.h>
#include "graph.h"
#include "stack.h"
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
int init_graph(graph_t *g_p)
{
    addEdge(g_p, A, B, 1);
    addEdge(g_p, A, C, 1);
    addEdge(g_p, B, D, 1);
    addEdge(g_p, C, E, 1);
    addEdge(g_p, C, F, 1);
    addEdge(g_p, D, G, 1);
    addEdge(g_p, D, H, 1);
    return 0;
}
void dls(graph_t *g_p, int root, int goal, int limit)
{
    printf("Depth Limited Search\n");
    int node, depth, to;
    stack_t *s_p, *sd_p;
    s_p = createStack(10);
    sd_p = createStack(10);
    pushStack(s_p, root);
    pushStack(sd_p, 0);
    while (!isEmptyStack(s_p))
    {
        printf("|");
        node = popStack(s_p);
        depth = popStack(sd_p);
        int countervar = 0;
        while (countervar < depth)
        {
            printf("-");
            countervar++;
        }
        printf("%d - depth: %d\n", node, depth);
        if (node == goal)
        {
            printf("Goal node %d found at depth %d\n", goal, depth);
            break;
        }
        if (depth < limit)
        {
            for (to = g_p->nodes - 1; to > 0; to--)
            {
                if (getEdge(g_p, node, to))
                {
                    pushStack(s_p, to);
                    pushStack(sd_p, depth + 1);
                }
            }
        }
        printf("\n");
    }
    destroyStack(s_p);
    destroyStack(sd_p);
    return;
}
int main()
{
    graph_t *g_p;
    g_p = createGraph(8);
    init_graph(g_p);
    displayGraph(g_p);
    dls(g_p, 0, 5, 2);
    destroyGraph(g_p);
    return 0;
}