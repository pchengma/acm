// LeetCode: 199. Binary Tree Right Side View (Medium)
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
class RightSideView {
public:
    void recursion(TreeNode *node, int level, vector<int> &res) {
        if (node == NULL) {
            return;
        }

        if (level == res.size()) {
            res.push_back(node->val);
        }

        recursion(node->right, level + 1, res);
        recursion(node->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};