// LeetCode: 1457. Pseudo-Palindromic Paths in a Binary Tree (Medium)
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
class PseudoPalindromicPaths {
public:
    bool isValid(const map<int, int> &nums) {
        int odds = 0;
        for (auto n: nums) {
            if (n.second % 2 != 0) {
                odds++;
            }
            if (odds > 1) {
                return false;
            }
        }
        return true;
    }

    void dfs(TreeNode *node, map<int, int> &path, int &res) {
        if (node->left == nullptr && node->right == nullptr) {
            path[node->val]++;
            if (isValid(path)) {
                res++;
            }
            path[node->val]--;
            return;
        }
        path[node->val]++;
        if (node->left != nullptr) {
            dfs(node->left, path, res);
        }
        if (node->right != nullptr) {
            dfs(node->right, path, res);
        }
        path[node->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        map<int, int> path;
        dfs(root, path, res);
        return res;
    }
};