// LeetCode: 1448. Count Good Nodes in Binary Tree (Medium)
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
    int goodNodes(TreeNode *root) {
        int res = 0;

        dfs(root, root->val, res);
        return res;
    }

    void dfs(TreeNode *node, int cur, int &res) {
        if (!node) {
            return;
        }

        if (node->val >= cur) {
            res++;
            cur = node->val;
        }

        dfs(node->left, cur, res);
        dfs(node->right, cur, res);
    }
};