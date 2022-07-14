// LeetCode: 105. Construct Binary Tree from Preorder and Inorder Traversal (Medium)
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
class BuildTree {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        int Idx = 0;
        return helper(preorder, inorder, Idx, 0, n - 1);
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int &Idx, int left, int right) {
        if (left > right) {
            return NULL;
        }

        int pivot = left;
        while (inorder[pivot] != preorder[Idx]) {
            pivot++;
        }

        Idx++;
        TreeNode *newNode = new TreeNode(inorder[pivot]);
        newNode->left = helper(preorder, inorder, Idx, left, pivot - 1);
        newNode->right = helper(preorder, inorder, Idx, pivot + 1, right);
        return newNode;
    }
};