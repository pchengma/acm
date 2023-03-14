// LeetCode: 129. Sum Root to Leaf Numbers (Medium)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root, int prevSum) {
    if (root == NULL) {
        return 0;
    }
    int sum = prevSum * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        return sum;
    } else {
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
}

int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}

