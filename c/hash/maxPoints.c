// LeetCode: 149. Max Points on a Line (Hard)
struct HashTable {
    int key, val;
    UT_hash_handle hh;
};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int maxPoints(int **points, int pointsSize, int *pointsColSize) {
    int n = pointsSize;
    if (n <= 2) {
        return n;
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (ret >= n - i || ret > n / 2) {
            break;
        }
        struct HashTable *hashTable = NULL;
        for (int j = i + 1; j < n; j++) {
            int x = points[i][0] - points[j][0];
            int y = points[i][1] - points[j][1];
            if (x == 0) {
                y = 1;
            } else if (y == 0) {
                x = 1;
            } else {
                if (y < 0) {
                    x = -x;
                    y = -y;
                }
                int gcdXY = gcd(abs(x), abs(y));
                x /= gcdXY, y /= gcdXY;
            }
            struct HashTable *tmp;
            int val = y + x * 20010;
            HASH_FIND_INT(hashTable, &val, tmp);
            if (tmp == NULL) {
                tmp = malloc(sizeof(struct HashTable));
                tmp->key = val;
                tmp->val = 1;
                HASH_ADD_INT(hashTable, key, tmp);
            } else {
                tmp->val++;
            }
        }
        int maxn = 0;
        struct HashTable *iter, *tmp;
        HASH_ITER(hh, hashTable, iter, tmp)
        {
            maxn = fmax(maxn, iter->val + 1);
            HASH_DEL(hashTable, iter);
            free(iter);
        }
        ret = fmax(ret, maxn);
    }
    return ret;
}
