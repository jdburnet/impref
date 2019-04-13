#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

void init(struct Graph *g, bool directed)
{
    int i;

    g->numverts = 0;
    g->numedges = 0;
    g->directed = directed;

    for (i = 0; i < MAXV; i++)
    {
        g->edges[i] = NULL;
        g->degree[i] = 0;
        g->state[i] = UNDISCOVERED;
    }
}

void insertedge(struct Graph *g, int x, int y)
{
    _insertedge(g, x, y);
    if (!g->directed)
    {
        _insertedge(g, y, x);
    }
}

void _insertedge(struct Graph *g, int x, int y)
{
    struct EdgeNode *p = malloc(sizeof(struct EdgeNode));
    p->weight = 1;  // not used for now
    p->y = y;

    if (!g->edges[x])
    {
        g->numverts++;
    }
    p->next = g->edges[x];
    g->edges[x] = p;
    
    g->degree[x]++;

    g->numedges++;
}

void bfs(struct Graph *g, int start)
{
    /* import queue once integrated and implement */
}

void dfs(struct Graph *g, int v)
{
    struct EdgeNode *p;
    int y;

    g->state[v] = PROCESSING;

    p = g->edges[v];
    while (p)
    {
        y = p->y;
        if (g->state[y] == UNDISCOVERED)
        {
            g->edges[y]->parent = v;
            printf("%d: %d", v, y);
            dfs(g, y);
        }
        p = p->next;
    }

    g->state[v] = PROCESSED;
}

int main(int argc, char **argv)
{
    struct Graph *g = malloc(sizeof(struct Graph));
    init(g, true);
    assert(g);
    insertedge(g, 1, 2);
    assert(g->edges[1]->y == 2);
    assert(!g->edges[2]);

    init(g, false);
    assert(g);
    insertedge(g, 1, 2);
    assert(g->edges[1]->y == 2);
    assert(g->edges[2]->y == 1);

    return 0;
}
