// LeetCode: 2306. Naming a Company (Hard)
typedef struct {
    char val[11];
    UT_hash_handle hh;
} Hash;

long long distinctNames(char **ideas, int ideasSize) {
    int n = ideasSize;
    long long res = 0;
    int dp[26][26] = {0};
    Hash *hs = NULL;
    Hash *tmp = NULL;
    char idea[11];

    for (int i = 0; i < n; ++i) {
        Hash *node = (Hash *) calloc(1, sizeof(Hash));
        strcpy(node->val, ideas[i]);
        HASH_FIND_STR(hs, node->val, tmp);
        if (tmp == NULL) {
            HASH_ADD_STR(hs, val, node);
        }
    }
    for (int i = 0; i < n; ++i) {
        int pre = ideas[i][0] - 'a';
        for (int j = 0; j < 26; ++j) {
            idea[0] = j + 'a';
            strcpy(idea + 1, ideas[i] + 1);
            HASH_FIND_STR(hs, idea, tmp);
            if (tmp == NULL) {
                dp[pre][j] += 1;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            res += dp[i][j] * dp[j][i];
        }
    }
    return res;
}
