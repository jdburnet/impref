#define MAXV 1000

struct EdgeNode
{
    int y;                   /* adjacency info, i.e. (x, y) */
    int weight;              /* edge weight, if any */
    struct EdgeNode *next;

};

struct Graph
{
    int numverts;
    int numedges;
    struct EdgeNode *edges[MAXV];
    int degree[MAXV];
    bool directed;  
};

void init(struct Graph *g, bool directed);

void insertedge(struct Graph *g, int x, int y);

void _insertedge(struct Graph *g, int x, int y);
