// LeetCode: 2300. Successful Pairs of Spells and Potions (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int cmp1(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

static int cmp2(const void *a, const void *b) {
    return ((int *) a)[0] - ((int *) b)[0];
}

int *successfulPairs(int *spells, int spellsSize, int *potions, int potionsSize, long long success, int *returnSize) {
    int *res = (int *) calloc(spellsSize, sizeof(int));
    int idx[spellsSize][2];
    for (int i = 0; i < spellsSize; i++) {
        idx[i][0] = spells[i];
        idx[i][1] = i;
    }

    qsort(potions, potionsSize, sizeof(int), cmp1);
    qsort(idx, spellsSize, sizeof(idx[0]), cmp2);
    for (int i = 0, j = 0; i < spellsSize; ++i) {
        int p = idx[i][1];
        int v = idx[i][0];
        while (j < potionsSize && (long long) potions[j] * v >= success) {
            ++j;
        }
        res[p] = j;
    }
    *returnSize = spellsSize;
    return res;
}
