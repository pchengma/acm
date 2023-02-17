// LeetCode: 783. Minimum Distance Between BST Nodes (Easy)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode *root, int *pre, int *ans) {
    if (root == NULL) {
        return;
    }
    dfs(root->left, pre, ans);
    if (*pre == -1) {
        *pre = root->val;
    } else {
        *ans = fmin(*ans, root->val - (*pre));
        *pre = root->val;
    }
    dfs(root->right, pre, ans);
}

int minDiffInBST(struct TreeNode *root) {
    int ans = INT_MAX, pre = -1;
    dfs(root, &pre, &ans);
    return ans;
}
