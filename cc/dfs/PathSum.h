// LeetCode: 113. Path Sum II (Medium)
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
    vector <vector<int>> result;

    void dfs(TreeNode *root, vector<int> &v, int &targetSum) {
        if (root == NULL) {
            return;
        }

        v.push_back(root->val);
        targetSum -= root->val;

        if (!root->left && !root->right) {
            if (targetSum == 0) {
                result.push_back(v);
            }
            v.pop_back();
            targetSum += root->val;
            return;
        }

        dfs(root->left, v, targetSum);
        dfs(root->right, v, targetSum);
        v.pop_back();
        targetSum += root->val;
    }

    vector <vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> v = {};
        dfs(root, v, targetSum);
        return result;
    }
};