// LeetCode: 958. Check Completeness of a Binary Tree (Medium)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isCompleteTree(struct TreeNode *root) {
    if (root == NULL) {
        return false;
    }
    struct TreeNode *queue[20000];
    int low = 0, high = 1;
    queue[low] = root;
    while (low < high) {
        if (queue[low] == NULL) {
            low++;
        } else {
            queue[high++] = queue[low]->left;
            queue[high++] = queue[low]->right;
            low++;
        }
    }
    for (int i = 0; i < high; i++) {
        if (queue[i] == NULL) {
            for (int j = i + 1; j < high; j++) {
                if (queue[j] != NULL) {
                    return false;
                }
            }
        }
    }
    return true;
}
