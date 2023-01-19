// LeetCode: 974. Subarray Sums Divisible by K (Medium)
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashTab;

int subarraysDivByK(int *nums, int numsSize, int k) {
    int ret = 0;
    HashTab *head = NULL;
    HashTab *p = NULL;
    p = malloc(sizeof(HashTab));
    p->key = 0;
    p->val = 1;
    HASH_ADD_INT(head, key, p);
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
        int need = (sum % k + k) % k;
        HASH_FIND_INT(head, &need, p);
        if (p != NULL) {
            ret += p->val;
            ++p->val;
        } else {
            p = malloc(sizeof(HashTab));
            p->key = need;
            p->val = 1;
            HASH_ADD_INT(head, key, p);
        }
    }
    return ret;
}
