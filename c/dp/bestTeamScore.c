// LeetCode: 1626. Best Team With No Conflicts (Medium)
int cmp(int **a, int **b) {
    return (*a)[1] == (*b)[1] ? (*a)[0] - (*b)[0] : (*a)[1] - (*b)[1];
}

int bestTeamScore(int *scores, int scoresSize, int *ages, int agesSize) {
    int **data = malloc(scoresSize * sizeof(int *));
    for (int i = 0; i < scoresSize; i++) {
        data[i] = malloc(2 * sizeof(int));
        data[i][0] = scores[i];
        data[i][1] = ages[i];
    }
    qsort(data, scoresSize, sizeof(int *), cmp);

    int max = data[0][0];
    int dp[scoresSize];
    for (int i = 0; i < scoresSize; i++) {
        dp[i] = data[i][0];
        for (int j = 0; j < i; j++) {
            if (data[j][0] <= data[i][0]) {
                dp[i] = fmax(dp[j] + data[i][0], dp[i]);
            }
        }
        max = fmax(max, dp[i]);
    }

    return max;
}