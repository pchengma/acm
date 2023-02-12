// LeetCode: 2477. Minimum Fuel Cost to Report to the Capital (Medium)
#define N 100010
int e[N * 2], ne[N * 2], idx, h[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

long long ans;

int dfs(int fa, int x, int seats) {
    int i, size;

    size = 1;
    for (i = h[x]; i != -1; i = ne[i]) {
        if (e[i] != fa)
            size += dfs(x, e[i], seats);
    }
    if (x)
        ans += 1ULL * (size + seats - 1) / seats;
    return size;
}

long long minimumFuelCost(int **roads, int roadsSize, int *roadsColSize, int seats) {
    int i;

    idx = ans = 0, memset(h, -1, sizeof(h));
    for (i = 0; i < roadsSize; i++) {
        add(roads[i][0], roads[i][1]);
        add(roads[i][1], roads[i][0]);
    }
    dfs(-1, 0, seats);
    return ans;
}
