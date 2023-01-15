// LeetCode: 2421. Number of Good Paths (Hard)
#define N 30010
int e[2 * N], h[N], ne[2 * N], idx, p[N];

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int cmp(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

int numberOfGoodPaths(int *vals, int n, int **edges, int edgesSize, int *edgesColSize) {
    int i, j, ans, size[N], fx, fy;
    int v[N][2];

    for (i = 0; i < n; i++) {
        v[i][0] = vals[i];
        v[i][1] = i;
    }
    qsort(v, n, sizeof(2 * sizeof(int)), cmp);

    idx = 0, memset(h, -1, sizeof(h));
    for (i = 0; i < edgesSize; i++) {
        add(edges[i][0], edges[i][1]);
        add(edges[i][1], edges[i][0]);
    }

    for (i = 0; i < n; i++) {
        p[i] = i;
        size[i] = 1;
    }

    for (ans = n, i = 0; i < n; i++) {
        fx = find(v[i][1]);
        for (j = h[v[i][1]]; j != -1; j = ne[j]) {
            fy = find(e[j]);
            if (fx != fy && vals[fy] <= v[i][0]) {
                if (vals[fy] == v[i][0]) {
                    ans += size[fy] * size[fx];
                    size[fx] += size[fy];
                }
                p[fy] = fx;
            }
        }
    }

    return ans;
}