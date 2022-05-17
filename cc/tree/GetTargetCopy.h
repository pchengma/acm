// LeetCode: 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class GetTargetCopy {
public:
    TreeNode *traverse(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (!original) {
            return NULL;
        }

        if (original == target) {
            return cloned;
        }

        return max(traverse(original->left, cloned->left, target), traverse(original->right, cloned->right, target));
    }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        return traverse(original, cloned, target);
    }
};