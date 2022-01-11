// LeetCode: 1022. Sum of Root To Leaf Binary Numbers (Easy)
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
    int ans = 0;

    void search(TreeNode *node, int pre = 0) {
        if (!node->left and !node->right) {
            this->ans += pre * 2 + node->val;
        }

        if (node->left) {
            search(node->left, pre * 2 + node->val);
        }

        if (node->right) {
            search(node->right, pre * 2 + node->val);
        }
    }

    int sumRootToLeaf(TreeNode *root) {
        search(root);
        return this->ans;
    }
};