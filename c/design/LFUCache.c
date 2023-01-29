// LeetCode: 460. LFU Cache (Hard)
typedef struct CacheList_ {
    int key;
    int value;
    int freq;
    struct CacheList_ *pre;
    struct CacheList_ *next;
} CacheList;

typedef struct {
    int cnt;
    int capacity;
    int minFreq;
    CacheList freqTbl[200001];
    CacheList *keyTbl[100001];
} LFUCache;

void OptFreq(LFUCache *obj, CacheList *cur) {
    if ((cur->freq == obj->minFreq) &&
        (obj->freqTbl[obj->minFreq].pre == obj->freqTbl[obj->minFreq].next)) {
        obj->minFreq++;
    }
    cur->freq++;

    cur->pre->next = cur->next;
    cur->next->pre = cur->pre;

    cur->pre = &obj->freqTbl[cur->freq];
    cur->next = obj->freqTbl[cur->freq].next;
    obj->freqTbl[cur->freq].next->pre = cur;
    obj->freqTbl[cur->freq].next = cur;
}

LFUCache *lFUCacheCreate(int capacity) {
    LFUCache *ret = (LFUCache *) calloc(1, sizeof(LFUCache));
    ret->capacity = capacity;
    for (int i = 0; i < 200001; i++) {
        ret->freqTbl[i].pre = &ret->freqTbl[i];
        ret->freqTbl[i].next = &ret->freqTbl[i];
    }
    return ret;
}

int lFUCacheGet(LFUCache *obj, int key) {
    if (obj->keyTbl[key] == NULL) {
        return -1;
    }
    CacheList *cur = obj->keyTbl[key];

    OptFreq(obj, cur);

    return cur->value;
}

void PrintList(LFUCache *obj) {
    for (int i = 0; i < 200001; i++) {
        CacheList *cur = obj->freqTbl[i].next;
        if (cur == &obj->freqTbl[i]) {
            continue;
        }
        printf("freq: %d ", i);
        CacheList *tmp = cur;
        while (cur != &obj->freqTbl[i]) {
            printf("%d ", cur->key);
            cur = cur->next;
        }
        printf("\n");
    }
    printf("\n");
}

void lFUCachePut(LFUCache *obj, int key, int value) {
    if (obj->capacity == 0) {
        return;
    }
    if (obj->keyTbl[key] == NULL) {
        if (obj->cnt >= obj->capacity) {
            CacheList *cur = obj->freqTbl[obj->minFreq].pre;

            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;

            obj->keyTbl[cur->key] = NULL;
            free(cur);

            obj->cnt--;
        }

        CacheList *cur = (CacheList *) calloc(1, sizeof(CacheList));
        cur->key = key;
        cur->value = value;
        cur->freq = 1;

        cur->pre = &obj->freqTbl[cur->freq];
        cur->next = obj->freqTbl[cur->freq].next;
        obj->freqTbl[cur->freq].next->pre = cur;
        obj->freqTbl[cur->freq].next = cur;

        obj->keyTbl[key] = cur;

        obj->cnt++;
        obj->minFreq = 1;
    } else {
        CacheList *cur = obj->keyTbl[key];
        cur->key = key;
        cur->value = value;

        OptFreq(obj, cur);
    }
}

void lFUCacheFree(LFUCache *obj) {
    for (int i = 0; i < 200001; i++) {
        CacheList *cur = obj->freqTbl[i].next;
        CacheList *tmp = cur;
        while (cur != &obj->freqTbl[i]) {
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(obj);
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/