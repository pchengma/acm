// LeetCode: 872. Leaf-Similar Trees (Easy)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int pos;

void GetLeafNodes(struct TreeNode *root, int *leaf) {
    if (root->left != NULL) {
        GetLeafNodes(root->left, leaf);
    }
    if (root->right != NULL) {
        GetLeafNodes(root->right, leaf);
    }
    if (root->left == NULL && root->right == NULL) {
        leaf[pos] = root->val;
        pos++;
    }
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2) {
    int i;

    int *leaf1 = (int *) malloc(sizeof(int) * 200);
    int *leaf2 = (int *) malloc(sizeof(int) * 200);

    pos = 0;
    GetLeafNodes(root1, leaf1);

    int tempLen = pos;
    pos = 0;
    GetLeafNodes(root2, leaf2);

    int len = (tempLen > pos) ? tempLen : pos;
    for (i = 0; i < len; i++) {
        if (leaf1[i] != leaf2[i]) {
            return false;
        }
    }
    return true;
}