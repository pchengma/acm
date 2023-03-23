// LeetCode: 1319. Number of Operations to Make Network Connected (Medium)
void dfs(int** edges, int* edgesColSize, int* used, int u) {
    used[u] = true;
    for (int i = 0; i < edgesColSize[u]; i++) {
        int v = edges[u][i];
        if (!used[v]) {
            dfs(edges, edgesColSize, used, v);
        }
    }
}

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    if (connectionsSize < n - 1) {
        return -1;
    }

    int* edges[n];
    int edgesColSize[n];
    memset(edgesColSize, 0, sizeof(edgesColSize));
    for (int i = 0; i < connectionsSize; i++) {
        edgesColSize[connections[i][0]]++;
        edgesColSize[connections[i][1]]++;
    }
    for (int i = 0; i < n; i++) {
        edges[i] = malloc(sizeof(int) * edgesColSize[i]);
        edgesColSize[i] = 0;
    }

    for (int i = 0; i < connectionsSize; i++) {
        int x = connections[i][0], y = connections[i][1];
        edges[x][edgesColSize[x]++] = y;
        edges[y][edgesColSize[y]++] = x;
    }

    int used[n];
    memset(used, 0, sizeof(used));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(edges, edgesColSize, used, i);
            ++ans;
        }
    }

    return ans - 1;
}

