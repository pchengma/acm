// LeetCode: 897. Increasing Order Search Tree (Easy)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, TreeNode *&dummy) {
        if (!root) {
            return;
        }

        dfs(root->left, dummy);
        TreeNode *newNode = new TreeNode(root->val);
        dummy->right = newNode;
        dummy = dummy->right;
        dfs(root->right, dummy);

        return;
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *dummy = new TreeNode(0);
        TreeNode *ans = dummy;
        dfs(root, dummy);
        return ans->right;
    }
};