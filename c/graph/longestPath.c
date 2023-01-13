// LeetCode: 2246. Longest Path With Different Adjacent Characters (Hard)
typedef struct node {
    int ver;
    struct node *next;
} Node;

typedef struct aList {
    Node *head;
} aList;

typedef struct graph {
    int v;
    aList *list;
} Graph;

Node *newaList(int v) {
    Node *newNode = calloc(sizeof(Node), 1);
    newNode->ver = v;
    return newNode;
}

Graph *createGraph(int v) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->v = v;

    graph->list = calloc(sizeof(aList), v);
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    Node *newNode = newaList(dest);
    newNode->next = graph->list[src].head;
    graph->list[src].head = newNode;
}

int dfs(int node, Graph *g, char *s, int *result) {
    int longest = 0, secondLongest = 0;
    Node *child = g->list[node].head;
    while (child) {
        int pathLen = dfs(child->ver, g, s, result);
        if (s[node] != s[child->ver]) {
            if (pathLen > longest) {
                secondLongest = longest;
                longest = pathLen;
            } else if (pathLen > secondLongest) {
                secondLongest = pathLen;
            }
        }
        child = child->next;
    }

    *result = fmax(*result, longest + secondLongest + 1);
    return longest + 1;
}

int longestPath(int *parent, int parentSize, char *s) {
    Graph *graph = createGraph(parentSize + 1);

    for (int i = 0; i < parentSize; i++) {
        if (parent[i] == -1)
            continue;
        else
            addEdge(graph, parent[i], i);
    }

    int result = 1;
    dfs(0, graph, s, &result);
    return result;
}