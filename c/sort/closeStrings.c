// LeetCode: 1657. Determine if Two Strings Are Close (Medium)
int compareFunc(void *a, void *b) {
    if (*(int *) a >= *(int *) b) {
        return 1;
    }
    return -1;
}

bool closeStrings(char *word1, char *word2) {
    int lenW1 = strlen(word1);
    int lenW2 = strlen(word2);
    if (lenW1 != lenW2) {
        return false;
    }

    int i;
    int vatW1[26] = {0};
    int vatW2[26] = {0};
    for (i = 0; i < lenW1; i++) {
        vatW1[word1[i] - 'a']++;
        vatW2[word2[i] - 'a']++;
    }


    for (i = 0; i < 26; i++) {
        if (vatW1[i]) {
            if (!vatW2[i]) {
                return false;
            }
        } else {
            if (vatW2[i]) {
                return false;
            }
        }
    }

    qsort(vatW1, 26, sizeof(int), compareFunc);
    qsort(vatW2, 26, sizeof(int), compareFunc);
    for (i = 0; i < 26; i++) {
        if (vatW1[i] != vatW2[i]) {
            return false;
        }
    }

    return true;
}
