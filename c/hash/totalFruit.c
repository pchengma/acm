// LeetCode: 904. Fruit Into Baskets (Medium)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem *hashFindItem(HashItem **obj, int key) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem **obj, int key, int val) {
    if (hashFindItem(obj, key)) {
        return false;
    }
    HashItem *pEntry = (HashItem *) malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem **obj, int key, int val) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        hashAddItem(obj, key, val);
    } else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem **obj, int key, int defaultVal) {
    HashItem *pEntry = hashFindItem(obj, key);
    if (!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem **obj) {
    HashItem *curr = NULL, *tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp)
    {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int totalFruit(int *fruits, int fruitsSize) {
    HashItem *cnt = NULL;
    int left = 0, ans = 0;
    for (int right = 0; right < fruitsSize; ++right) {
        hashSetItem(&cnt, fruits[right], hashGetItem(&cnt, fruits[right], 0) + 1);
        while (HASH_COUNT(cnt) > 2) {
            HashItem *pEntry = hashFindItem(&cnt, fruits[left]);
            pEntry->val--;
            if (pEntry->val == 0) {
                HASH_DEL(cnt, pEntry);
                free(pEntry);
            }
            ++left;
        }
        ans = MAX(ans, right - left + 1);
    }
    hashFree(&cnt);
    return ans;
}
