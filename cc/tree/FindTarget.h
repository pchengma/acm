// LeetCode: 653. Two Sum IV - Input is a BST (Easy)
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
class FindTarget {
public:
    bool helper(TreeNode *root, unordered_set<int> &map, int k) {
        if (root == NULL) return false;

        if (map.find(k - root->val) == map.end()) {
            map.insert(root->val);
        } else {
            return true;
        }
        return (helper(root->left, map, k) || helper(root->right, map, k));
    }

    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> map;
        return helper(root, map, k);
    }
};