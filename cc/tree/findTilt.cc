// LeetCode: 563. Binary Tree Tilt (Easy)
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
    int dfs(TreeNode *root, int &res) {
        int leftVal = 0;
        int rightVal = 0;

        if (!root) {
            return 0;
        }

        leftVal = dfs(root->left, res);
        rightVal = dfs(root->right, res);

        res += abs(leftVal - rightVal);

        return root->val + leftVal + rightVal;
    }

    int findTilt(TreeNode *root) {
        int res = 0;

        if (root) {
            dfs(root, res);
        }

        return res;
    }
};