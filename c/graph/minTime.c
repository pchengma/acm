// LeetCode: 1443. Minimum Time to Collect All Apples in a Tree (Medium)
#define START     0
#define END       1
#define DEBUG     false

#define MAX_LEN   20

int ans;

bool dfs(int n, bool *hasApple, int hasAppleSize, int index, int **buf, int *bufColSize) {
    if (index >= n) {
        return false;
    }

    int len = bufColSize[index];
    bool flag = false;
    bufColSize[index] = 0;

    for (int i = 0; i < len; ++i) {
        if (bufColSize[buf[index][i]] != 0 && dfs(n, hasApple, hasAppleSize, buf[index][i], buf, bufColSize)) {
            ans += 2;
            flag = true;
        }
    }

    return hasApple[index] || flag;
}

int minTime(int n, int **edges, int edgesSize, int *edgesColSize, bool *hasApple, int hasAppleSize) {
    ans = 0;
    int **buf = (int **) malloc(sizeof(int *) * n);
    int *bufColSize = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i) {
        buf[i] = (int *) malloc(sizeof(int) * MAX_LEN);
    }

    memset(bufColSize, 0, sizeof(int) * n);

    for (int i = 0; i < edgesSize; ++i) {
        buf[edges[i][START]][(bufColSize[edges[i][START]])++] = edges[i][END];
        buf[edges[i][END]][(bufColSize[edges[i][END]])++] = edges[i][START];
    }

#if DEBUG
    for (int i = 0; i < n; ++i) {
        printf( "%d: ", i);
        for( int j = 0; j < bufColSize[i]; ++j) {
            printf("%d ", buf[i][j]);
        }
        printf("\n");
    }
#endif
    dfs(n, hasApple, hasAppleSize, 0, buf, bufColSize);
    return ans;
}
