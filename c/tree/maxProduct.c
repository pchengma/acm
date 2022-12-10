// LeetCode: 1339. Maximum Product of Splitted Binary Tree (Medium)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int lsum, rsum, sum, m, n, min;

int dfs1(struct TreeNode *p) {
    if (!p) return 0;
    if (!p->left && !p->right) return p->val;
    lsum = dfs1(p->left);
    p->val += lsum;
    rsum = dfs1(p->right);
    return p->val += rsum;
}

void dfs2(struct TreeNode *p) {
    if (!p) return;
    if (abs((p->val) - (sum - p->val)) < min) {
        min = abs((p->val) - (sum - p->val));
        m = p->val;
        n = sum - p->val;
    }
    dfs2(p->left);
    dfs2(p->right);
}

int maxProduct(struct TreeNode *root) {
    min = INT_MAX;
    sum = dfs1(root);
    dfs2(root);
    return ((long) m * (long) n) % 1000000007;
}
