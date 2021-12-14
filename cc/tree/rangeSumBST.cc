// LeetCode: 938. Range Sum of BST (Easy)
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
    int sumofRange;

    void dfs(TreeNode *root, int L, int R) {

        if (!root) {
            return;
        }

        if (root->val >= L && root->val <= R) {
            sumofRange += root->val;
        }

        if (root->val > L) {
            dfs(root->left, L, R);
        }

        if (root->val < R) {
            dfs(root->right, L, R);
        }
    }

    int rangeSumBST(TreeNode *root, int L, int R) {
        sumofRange = 0;
        dfs(root, L, R);
        return sumofRange;
    }
};