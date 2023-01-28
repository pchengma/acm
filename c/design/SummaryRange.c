// LeetCode: 352. Data Stream as Disjoint Intervals (Hard)
typedef struct SummaryRanges {
    int left, right;
    struct SummaryRanges *pre, *next;
} SummaryRanges;

/** Initialize your data structure here. */
SummaryRanges *summaryRangesCreate() {
    SummaryRanges *head = malloc(sizeof(SummaryRanges)), *rear = malloc(sizeof(SummaryRanges));
    head->next = head->pre = rear;
    rear->next = rear->pre = head;
    head->left = 0;
    return head;
}

SummaryRanges *insert(SummaryRanges *head, SummaryRanges *rear, int val) {
    SummaryRanges *p = head->next;
    while (p != rear) {
        if (p->left <= val && val <= p->right) return NULL;
        else if (p->right < val) p = p->next;
        else break;
    }
    SummaryRanges *q = malloc(sizeof(SummaryRanges));
    q->left = q->right = val;
    q->next = p, q->pre = p->pre;
    p->pre->next = q, p->pre = q;
    ++head->left;
    return q;
}

void summaryRangesAddNum(SummaryRanges *obj, int val) {
    SummaryRanges *head = obj, *rear = obj->pre;
    SummaryRanges *p = insert(head, rear, val);
    if (!p) return;
    int f1 = p->pre != head && p->pre->right + 1 == p->left, f2 = p->next != rear && p->next->left - 1 == p->right;
    if (f1 && f2) {
        p->pre->right = p->next->right;
        p->pre->next = p->next->next;
        p->next->next->pre = p->pre;
        head->left -= 2;
        free(p->next);
        free(p);
    } else if (f1) {
        p->pre->right = p->right;
        p->pre->next = p->next;
        p->next->pre = p->pre;
        head->left--;
        free(p);
    } else if (f2) {
        p->next->left = p->left;
        p->next->pre = p->pre;
        p->pre->next = p->next;
        head->left--;
        free(p);
    }
}

int **summaryRangesGetIntervals(SummaryRanges *obj, int *rs, int **rcs) {
    SummaryRanges *p = obj->next, *rear = obj->pre;
    int **ret = malloc((obj->left) * sizeof(int *));
    *rs = 0;
    while (p != rear) {
        ret[*rs] = malloc(2 * sizeof(int));
        ret[*rs][0] = p->left, ret[*rs][1] = p->right;
        (*rs)++;
        p = p->next;
    }
    *rcs = malloc((*rs) * sizeof(int));
    for (int i = 0; i < *rs; ++i) (*rcs)[i] = 2;
    return ret;
}

void summaryRangesFree(SummaryRanges *obj) {
    SummaryRanges *p = obj->next, *rear = obj->pre;
    while (p != rear) {
        SummaryRanges *temp = p->next;
        free(p);
        p = temp;
    }
    free(rear);
    free(obj);
}

/**
 * Your SummaryRanges struct will be instantiated and called as such:
 * SummaryRanges* obj = summaryRangesCreate();
 * summaryRangesAddNum(obj, value);
 
 * int** param_2 = summaryRangesGetIntervals(obj, retSize, retColSize);
 
 * summaryRangesFree(obj);
*/