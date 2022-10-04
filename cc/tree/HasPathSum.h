// LeetCode: 112. Path Sum (Easy)
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
    bool preOrderTraversal(TreeNode *root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        if (root->right == NULL && root->left == NULL) {
            if (root->val == targetSum) {
                return true;
            }
        }
        bool left = preOrderTraversal(root->left, targetSum - (root->val));
        bool right = preOrderTraversal(root->right, targetSum - (root->val));
        return left | right;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        return preOrderTraversal(root, targetSum);
    }
};