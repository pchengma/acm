// LeetCode: 438. Find All Anagrams in a String (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool stringIsMatch(char *s, int len, char *vat) {
    int i;
    char vatBak[26] = {0};
    int temp;
    for (i = 0; i < len; i++) {
        temp = s[i] - 'a';
        vatBak[temp]++;
    }
    for (i = 0; i < 26; i++) {
        if (vat[i] != vatBak[i]) {
            return false;
        }
    }
    return true;
}

int *findAnagrams(char *s, char *p, int *returnSize) {
    char vat[26] = {0};
    int i;
    int temp = 0;

    *returnSize = 0;
    int *returnNums = (int *) malloc(sizeof(int) * strlen(s));
    if (strlen(s) < strlen(p)) {
        return returnNums;
    }

    for (i = 0; i < strlen(p); i++) {
        temp = p[i] - 'a';
        vat[temp]++;
    }

    for (i = 0; i <= (strlen(s) - strlen(p)); i++) {
        if (stringIsMatch(s + i, strlen(p), vat)) {
            returnNums[*returnSize] = i;
            *returnSize = *returnSize + 1;
        }
    }
    return returnNums;
}
