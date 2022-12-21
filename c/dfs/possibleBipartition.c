// LeetCode: 886. Possible Bipartition (Medium)
bool dfs(int curnode, int nowcolor, int *color, struct ListNode **g) {
    color[curnode] = nowcolor;
    for (struct ListNode *nextnode = g[curnode]; nextnode; nextnode = nextnode->next) {
        if (color[nextnode->val] && color[nextnode->val] == color[curnode]) {
            return false;
        }
        if (!color[nextnode->val] && !dfs(nextnode->val, 3 ^ nowcolor, color, g)) {
            return false;
        }
    }
    return true;
}

bool possibleBipartition(int n, int **dislikes, int dislikesSize, int *dislikesColSize) {
    int color[n + 1];
    struct ListNode *g[n + 1];
    for (int i = 0; i <= n; i++) {
        color[i] = 0;
        g[i] = NULL;
    }
    for (int i = 0; i < dislikesSize; i++) {
        int a = dislikes[i][0], b = dislikes[i][1];
        struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
        node->val = a;
        node->next = g[b];
        g[b] = node;
        node = (struct ListNode *) malloc(sizeof(struct ListNode));
        node->val = b;
        node->next = g[a];
        g[a] = node;
    }
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0 && !dfs(i, 1, color, g)) {
            for (int j = 0; j <= n; j++) {
                struct ListNode *node = g[j];
                while (node) {
                    struct ListNode *prev = node;
                    node = node->next;
                    free(prev);
                }
            }
            return false;
        }
    }
    for (int j = 0; j <= n; j++) {
        struct ListNode *node = g[j];
        while (node) {
            struct ListNode *prev = node;
            node = node->next;
            free(prev);
        }
    }
    return true;
}
