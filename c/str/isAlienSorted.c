// LeetCode: 953. Verifying an Alien Dictionary (Easy)
bool isAlienSorted(char **words, int wordsSize, char *order) {
    int index[26];
    int len = strlen(order);
    for (int i = 0; i < len; i++) {
        index[order[i] - 'a'] = i;
    }
    for (int i = 1; i < wordsSize; i++) {
        bool valid = false;
        int l1 = strlen(words[i - 1]);
        int l2 = strlen(words[i]);
        int n = l1 < l2 ? l1 : l2;
        for (int j = 0; j < n; j++) {
            int prev = index[words[i - 1][j] - 'a'];
            int curr = index[words[i][j] - 'a'];
            if (prev < curr) {
                valid = true;
                break;
            } else if (prev > curr) {
                return false;
            }
        }
        if (!valid) {
            if (l1 > l2) {
                return false;
            }
        }
    }
    return true;
}
