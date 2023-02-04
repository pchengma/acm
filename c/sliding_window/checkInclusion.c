// LeetCode: 567. Permutation in String (Medium)
bool equals(int *cnt1, int *cnt2) {
    for (int i = 0; i < 26; i++) {
        if (cnt1[i] != cnt2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(char *s1, char *s2) {
    int n = strlen(s1), m = strlen(s2);
    if (n > m) {
        return false;
    }
    int cnt1[26], cnt2[26];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < n; ++i) {
        ++cnt1[s1[i] - 'a'];
        ++cnt2[s2[i] - 'a'];
    }
    if (equals(cnt1, cnt2)) {
        return true;
    }
    for (int i = n; i < m; ++i) {
        ++cnt2[s2[i] - 'a'];
        --cnt2[s2[i - n] - 'a'];
        if (equals(cnt1, cnt2)) {
            return true;
        }
    }
    return false;
}
