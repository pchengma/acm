// LeetCode: 99. Recover Binary Search Tree (Medium)
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
    vector<int> vec;

    void getAll(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        getAll(root->left);
        vec.push_back(root->val);
        getAll(root->right);
    }

    int pos = 0;

    void fixTree(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        fixTree(root->left);
        root->val = vec[pos++];
        fixTree(root->right);
    }

    void recoverTree(TreeNode *root) {
        getAll(root);
        sort(vec.begin(), vec.end());
        fixTree(root);
    }
};