// LeetCode: 1129. Shortest Path with Alternating Colors (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct ListNode *createListNode(int val) {
    struct ListNode *obj = (struct ListNode *) malloc(sizeof(struct ListNode));
    obj->val = val;
    obj->next = NULL;
    return obj;
}

void freeList(struct ListNode *list) {
    while (list) {
        struct ListNode *cur = list;
        list = list->next;
        free(cur);
    }
}

int *shortestAlternatingPaths(int n, int **redEdges, int redEdgesSize, int *redEdgesColSize, int **blueEdges,
                              int blueEdgesSize, int *blueEdgesColSize, int *returnSize) {
    struct ListNode *next[2][n];
    for (int i = 0; i < n; i++) {
        next[0][i] = NULL;
        next[1][i] = NULL;
    }
    for (int i = 0; i < redEdgesSize; i++) {
        struct ListNode *node = createListNode(redEdges[i][1]);
        node->next = next[0][redEdges[i][0]];
        next[0][redEdges[i][0]] = node;
    }
    for (int i = 0; i < blueEdgesSize; i++) {
        struct ListNode *node = createListNode(blueEdges[i][1]);
        node->next = next[1][blueEdges[i][0]];
        next[1][blueEdges[i][0]] = node;
    }

    int dist[2][n];
    for (int i = 0; i < n; i++) {
        dist[0][i] = dist[1][i] = INT_MAX;
    }

    dist[0][0] = 0;
    dist[1][0] = 0;
    int queue[n * 2][2];
    int head = 0, tail = 0;
    queue[tail][0] = 0, queue[tail++][1] = 0;
    queue[tail][0] = 0, queue[tail++][1] = 1;
    while (head != tail) {
        int x = queue[head][0], t = queue[head][1];
        head++;
        for (struct ListNode *node = next[1 - t][x]; node != NULL; node = node->next) {
            int y = node->val;
            if (dist[1 - t][y] != INT_MAX) {
                continue;
            }
            dist[1 - t][y] = dist[t][x] + 1;
            queue[tail][0] = y, queue[tail++][1] = 1 - t;
        }
    }
    int *answer = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        answer[i] = MIN(dist[0][i], dist[1][i]);
        if (answer[i] == INT_MAX) {
            answer[i] = -1;
        }
    }
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        freeList(next[0][i]);
        freeList(next[1][i]);
    }
    return answer;
}
