// LeetCode: 446. Arithmetic Slices II - Subsequence (Hard)
#define HASH_FIND_LONG(head, findint, out) HASH_FIND(hh, head, findint, sizeof(long), out)
#define HASH_ADD_LONG(head, intfield, add) HASH_ADD(hh, head, intfield, sizeof(long), add)

struct HashTable {
    long key;
    int val;
    UT_hash_handle hh;
};

int query(struct HashTable **HashTable, long ikey) {
    struct HashTable *tmp;
    HASH_FIND_LONG(*HashTable, &ikey, tmp);
    return tmp == NULL ? 0 : tmp->val;
}

void add(struct HashTable **HashTable, long ikey, int ival) {
    struct HashTable *tmp;
    HASH_FIND_LONG(*HashTable, &ikey, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(struct HashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_LONG(*HashTable, key, tmp);
    } else {
        tmp->val += ival;
    }
}

int numberOfArithmeticSlices(int *nums, int numsSize) {
    int ans = 0;
    struct HashTable *hashTable[numsSize];
    memset(hashTable, 0, sizeof(hashTable));
    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < i; ++j) {
            long long d = 1LL * nums[i] - nums[j];
            int cnt = query(&hashTable[j], d);
            ans += cnt;
            add(&hashTable[i], d, cnt + 1);
        }
    }
    return ans;
}
