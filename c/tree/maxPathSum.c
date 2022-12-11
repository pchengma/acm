// LeetCode: 124. Binary Tree Maximum Path Sum (Hard)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxPathSum(struct TreeNode *root) {
    int max = INT_MIN;
    int val = root->val;
    if (root->left) {
        int left = maxPathSum(root->left);
        max = MAX(max, left);
        val = MAX(val, root->val + root->left->val);
    }
    if (root->right) {
        int right = maxPathSum(root->right);
        max = MAX(max, right);
        val = MAX(val, root->val + root->right->val);
    }
    if (root->left && root->right) {
        max = MAX(max, root->val + root->left->val + root->right->val);
    }
    root->val = val;
    max = MAX(max, root->val);
    return max;
}
