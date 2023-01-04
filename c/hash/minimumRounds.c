// LeetCode: 2244. Minimum Rounds to Complete All Tasks (Medium)
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} Map;
Map *map;

int minimumRounds(int *tasks, int tasksSize) {
    map = NULL;
    Map *temp = NULL;
    int count = 0;
    for (int i = 0; i < tasksSize; i++) {
        HASH_FIND_INT(map, &tasks[i], temp);
        if (temp == NULL) {
            temp = (Map *) malloc(sizeof(Map));
            temp->key = tasks[i];
            temp->val = 1;
            HASH_ADD_INT(map, key, temp);
        } else {
            (temp->val)++;
        }
    }
    Map *current = NULL;
    Map *next = NULL;
    HASH_ITER(hh, map, current, next)
    {
        if (current != NULL) {
            if (current->val == 1) {
                return -1;
            }
            int temp = current->val;
            int dup = temp % 3 == 0 ? 0 : 1;
            count += temp / 3 + dup;
        }
    }
    return count;
}
