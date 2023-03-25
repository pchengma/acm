// LeetCode: 2316. Count Unreachable Pairs of Nodes in an Undirected Graph (Medium)
typedef struct {
    int flag;
    int size;
}info; 

typedef struct {
    int key; 
    int size; 
    UT_hash_handle hh;
}mergedNode;

int getflag(info *node, int idx) {
    if (node[idx].flag != idx) {
        node[idx].flag = getflag(node, node[idx].flag);
    }
    return node[idx].flag;
}

void merge(int x, int y, info* node, mergedNode** hash) {
    int fx = getflag(node, x);
    int fy = getflag(node, y);
    if (fx == fy) { return; }
    node[fy].flag = fx;
    node[fx].size += node[fy].size;
    mergedNode *hx = NULL, *hy = NULL;
    HASH_FIND_INT(*hash, &fx, hx);
    if (hx) {
        hx->size = node[fx].size;
    } else {
        hx = (mergedNode*)calloc(1, sizeof(mergedNode));
        hx->key = fx;
        hx->size = node[fx].size;
        HASH_ADD_INT(*hash, key, hx);
    }
    HASH_FIND_INT(*hash, &fy, hy);
    if (hy) {
        HASH_DEL(*hash, hy);
    }
}

long long countPairs(int n, int** edges, int edgesSize, int* edgesColSize){
    info node[n];
    for (int i = 0; i < n; i++) {
        node[i].flag = i;
        node[i].size = 1; 
    }  
    mergedNode *hash = NULL;
    for (int i = 0; i < edgesSize; i++) {
        merge(edges[i][0], edges[i][1], node, &hash);
    }
    long long ans = (long long)n * (n-1) / 2;
    for (; hash; hash = hash->hh.next) {
        ans -= (long long) hash->size * (hash->size-1) / 2;
    }
    return ans; 
}

