#define MAXV 1000

struct EdgeNode
{
    int y;                   /* adjacency info, i.e. (x, y) */
    int weight;              /* edge weight, if any */
    int parent;
    struct EdgeNode *next;
};

enum NodeState {
    UNDISCOVERED,
    PROCESSING,
    PROCESSED,
};

struct Graph
{
    int numverts;
    int numedges;
    bool directed;
    struct EdgeNode *edges[MAXV];
    int degree[MAXV];
    enum NodeState state[MAXV];
};

void init(struct Graph *g, bool directed);

void insertedge(struct Graph *g, int x, int y);

void _insertedge(struct Graph *g, int x, int y);

void bfs(struct Graph *g, int start);

void dfs(struct Graph *g, int v);

bool hascycle(struct Graph *g, int v);

/* need to include stack struct */
bool toposort(struct Graph *dag, int root, struct Stack *sorted);
