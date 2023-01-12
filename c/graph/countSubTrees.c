// LeetCode: 1519. Number of Nodes in the Sub-Tree With the Same Label (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM 26
#define MAX_LEN 100000
#define MAX_NODE_NUM 100

int adj[MAX_LEN][MAX_NODE_NUM];
int count[MAX_LEN];

void dfs(int node, char *labels, int *visited, int **arr, int *res) {
    int child;
    int idx = labels[node] - 'a';
    visited[node] = 1;
    arr[node][idx] = 1;

    for (int i = 0; i < count[node]; i++) {
        child = adj[node][i];
        if (visited[child]) {
            continue;
        }
        dfs(child, labels, visited, arr, res);
        for (int j = 0; j < MAX_NUM; j++) {
            arr[node][j] += arr[child][j];
        }
    }

    res[node] = arr[node][idx];
    return;
}

int *countSubTrees(int n, int **edges, int edgesSize, int *edgesColSize, char *labels, int *returnSize) {
    int *res = (int *) malloc(sizeof(int) * n);
    memset(res, 0, sizeof(int) * n);
    *returnSize = n;
    int node1, node2;
    int visited[MAX_LEN] = {0};

    int **arr = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (int *) malloc(sizeof(int) * MAX_NUM);
        memset(arr[i], 0, sizeof(int) * MAX_NUM);
        count[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        node1 = edges[i][0];
        node2 = edges[i][1];
        adj[node1][count[node1]++] = node2;
        adj[node2][count[node2]++] = node1;
    }

    dfs(0, labels, visited, arr, res);
    return res;
}
