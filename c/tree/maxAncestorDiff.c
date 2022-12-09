// LeetCode: 1026. Maximum Difference Between Node and Ancestor (Medium)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int max_diff;

void helper(struct TreeNode *root, int max, int min) {
    max = MMAX(max, root->val);
    min = MMIN(min, root->val);

    if (root->left == NULL && root->right == NULL) {
        max_diff = MMAX(max_diff, max - min);
        return;
    }

    if (root->left != NULL) {
        helper(root->left, max, min);
    }

    if (root->right != NULL) {
        helper(root->right, max, min);
    }
}

int maxAncestorDiff(struct TreeNode *root) {
    max_diff = 0;

    helper(root, root->val, root->val);

    return max_diff;
}
