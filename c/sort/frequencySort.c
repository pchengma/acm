// LeetCode: 451. Sort Characters By Frequency (Medium)
#define LOWERCASE_ALPHABET_NUM 26
#define NUMBER_TYPE_NUM 10

#define TOTAL_ALPHABET_TYPE_NUM 52
#define TOTAL_TYPE_NUM 62

char *frequencySort(char *s) {
    int i = 0, j = 0;
    int len = strlen(s);
    int *hashTbl = (int *) malloc(sizeof(int) * TOTAL_TYPE_NUM);
    memset(hashTbl, 0u, sizeof(int) * TOTAL_TYPE_NUM);
    int *tmpHashTbl = (int *) malloc(sizeof(int) * TOTAL_TYPE_NUM);
    memset(tmpHashTbl, 0u, sizeof(int) * TOTAL_TYPE_NUM);

    for (i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            hashTbl[s[i] - 'a']++;
            tmpHashTbl[s[i] - 'a']++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            hashTbl[LOWERCASE_ALPHABET_NUM + s[i] - 'A']++;
            tmpHashTbl[LOWERCASE_ALPHABET_NUM + s[i] - 'A']++;
        } else {
            hashTbl[TOTAL_ALPHABET_TYPE_NUM + s[i] - '0']++;
            tmpHashTbl[TOTAL_ALPHABET_TYPE_NUM + s[i] - '0']++;
        }
    }

    // Sort:
    int *sortIdxTbl = (int *) malloc(sizeof(int) * TOTAL_TYPE_NUM);
    memset(sortIdxTbl, 0u, sizeof(int) * TOTAL_TYPE_NUM);
    int pos = 0;
    int idx = 0;
    int max = 0;
    for (i = 0; i < TOTAL_TYPE_NUM; i++) {
        for (j = 0; j < TOTAL_TYPE_NUM; j++) {
            if (tmpHashTbl[j] > max) {
                max = tmpHashTbl[j];
                idx = j;
            }
        }
        if (max > 0) {
            sortIdxTbl[pos] = idx;
            pos++;
            tmpHashTbl[idx] = 0;
            max = 0;
            idx = 0;
        }
    }

    char *res = (char *) malloc(sizeof(char) * (len + 1));
    memset(res, 'a', sizeof(char) * (len + 1));
    idx = 0;
    for (i = 0; i < pos; i++) {
        for (j = 0; j < hashTbl[sortIdxTbl[i]]; j++) {
            if (sortIdxTbl[i] < LOWERCASE_ALPHABET_NUM) {
                res[idx] = 'a' + sortIdxTbl[i];
            } else if (sortIdxTbl[i] >= LOWERCASE_ALPHABET_NUM && sortIdxTbl[i] < TOTAL_ALPHABET_TYPE_NUM) {
                res[idx] = 'A' + (sortIdxTbl[i] - LOWERCASE_ALPHABET_NUM);
            } else {
                res[idx] = '0' + (sortIdxTbl[i] - TOTAL_ALPHABET_TYPE_NUM);
            }
            idx++;
        }
    }
    res[len] = '\0';

    return res;
}