// LeetCode: 1834. Single-Threaded CPU (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int start;
    int time;
    int idx;
} Task;

typedef struct {
    Task *task;
    int idx;
} Heap;

int cmp1(const void *a, const void *b) {
    Task *aa = (Task *) a;
    Task *bb = (Task *) b;
    if (aa->start == bb->start) {
        return aa->time > bb->time;
    }
    return aa->start > bb->start;
}

int cmp2(Task *a, Task *b) {
    if (a->time == b->time) {
        return a->idx > b->idx;
    }
    return a->time > b->time;
}

void swap(Task *a, Task *b) {
    Task tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 最小堆初始化 */
Heap *initHeap(int n) {
    Heap *obj = (Heap *) malloc(sizeof(Heap));
    obj->task = (Task *) malloc(sizeof(Task) * n);
    obj->idx = 0;
    return obj;
}

void push(Heap *heap, Task *t) {
    heap->task[heap->idx++] = *t;
    int x = heap->idx - 1;
    int p;
    while (x > 0) {
        p = (x - 1) / 2;
        if (cmp2(&heap->task[p], &heap->task[x])) {
            swap(&heap->task[p], &heap->task[x]);
            x = p;
        } else {
            break;
        }
    }
}

Task pop(Heap *heap) {
    Task res = heap->task[0];
    heap->task[0] = heap->task[--heap->idx];
    int i = 0;
    int n = heap->idx;
    int min, l, r;
    while (i < n) {
        min = i;
        l = 2 * min + 1;
        r = 2 * min + 2;
        if (l < n && cmp2(&heap->task[min], &heap->task[l])) {
            min = l;
        }
        if (r < n && cmp2(&heap->task[min], &heap->task[r])) {
            min = r;
        }
        if (min != i) {
            swap(&heap->task[min], &heap->task[i]);
            i = min;
        } else {
            break;
        }
    }
    return res;
}

int *getOrder(int **tasks, int tasksSize, int *tasksColSize, int *returnSize) {
    int n = tasksSize;
    int *res = (int *) malloc(sizeof(int) * n);
    Heap *obj = initHeap(n);
    Task *task = (Task *) malloc(sizeof(Task) * n);
    int i, j;
    long cur = 0;

    for (i = 0; i < n; i++) {
        Task t = {tasks[i][0], tasks[i][1], i};
        task[i] = t;
    }

    qsort(task, n, sizeof(task[0]), cmp1);
    j = 0;
    for (i = 0; i < n; i++) {
        if (obj->idx == 0) {
            cur = fmax(cur, task[i].start);
        }
        while (j < n && task[j].start <= cur) {
            push(obj, &task[j]);
            j++;

        }
        Task tmp = pop(obj);
        res[i] = tmp.idx;
        cur += tmp.time;
    }
    *returnSize = n;
    return res;
}
