// LeetCode: 1971. Find if Path Exists in Graph (Easy)
struct ListNode *creatListNode(int val) {
    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

bool validPath(int n, int **edges, int edgesSize, int *edgesColSize, int source, int destination) {
    struct ListNode *adj[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = false;
    }
    for (int i = 0; i < edgesSize; i++) {
        int x = edges[i][0], y = edges[i][1];
        struct ListNode *nodex = creatListNode(x);
        nodex->next = adj[y];
        adj[y] = nodex;
        struct ListNode *nodey = creatListNode(y);
        nodey->next = adj[x];
        adj[x] = nodey;
    }
    int queue[n];
    int head = 0, tail = 0;
    queue[tail++] = source;
    visited[source] = true;
    while (head != tail) {
        int vertex = queue[head++];
        if (vertex == destination) {
            break;
        }
        for (struct ListNode *p = adj[vertex]; p != NULL; p = p->next) {
            int next = p->val;
            if (!visited[next]) {
                queue[tail++] = next;
                visited[next] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (struct ListNode *p = adj[i]; p != NULL;) {
            struct ListNode *cur = p;
            p = p->next;
            free(cur);
        }
    }
    return visited[destination];
}
