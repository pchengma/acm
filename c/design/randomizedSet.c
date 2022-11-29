// LeetCode: 380. Insert Delete GetRandom O(1) (Medium)
typedef struct {
    int val;
    UT_hash_handle hh;
} RandomizedSet;

RandomizedSet *set = NULL;

RandomizedSet *randomizedSetCreate() {
    return (RandomizedSet *) calloc(1, sizeof(RandomizedSet));
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
    RandomizedSet *tmp;
    HASH_FIND_INT(set, &val, tmp);
    if (tmp == NULL) {
        tmp = (RandomizedSet *) calloc(1, sizeof(RandomizedSet));
        tmp->val = val;
        HASH_ADD_INT(set, val, tmp);
        return true;
    }
    return false;
}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
    RandomizedSet *tmp;
    HASH_FIND_INT(set, &val, tmp);
    if (tmp != NULL) {
        HASH_DEL(set, tmp);
        free(tmp);
        return true;
    }
    return false;
}

int randomizedSetGetRandom(RandomizedSet *obj) {
    int cnt = 0;
    cnt = HASH_COUNT(set);
    int loop = rand() % cnt;
    RandomizedSet *current_user, *tmp;
    cnt = 0;
    HASH_ITER(hh, set, current_user, tmp)
    {
        if (cnt++ >= loop) {
            break;
        }
    }
    return current_user->val;
}

void randomizedSetFree(RandomizedSet *obj) {
    RandomizedSet *current_user, *tmp;
    HASH_ITER(hh, set, current_user, tmp)
    {
        HASH_DEL(set, current_user);
        free(current_user);
    }
    return;
}