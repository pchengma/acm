// LeetCode: 106. Construct Binary Tree from Inorder and Postorder Traversal (Medium)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int post_idx;

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} hashTable;

hashTable* idx_map;

void insertHashTable(int x, int y) {
    hashTable* rec = malloc(sizeof(hashTable));
    rec->key = x;
    rec->val = y;
    HASH_ADD_INT(idx_map, key, rec);
}

int queryHashTable(int x) {
    hashTable* rec;
    HASH_FIND_INT(idx_map, &x, rec);
    return rec->val;
}

struct TreeNode* helper(int in_left, int in_right, int* inorder, int* postorder) {
    if (in_left > in_right) {
        return NULL;
    }

    int root_val = postorder[post_idx];
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = root_val;

    int index = queryHashTable(root_val);

    post_idx--;
    root->right = helper(index + 1, in_right, inorder, postorder);
    root->left = helper(in_left, index - 1, inorder, postorder);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    post_idx = postorderSize - 1;
    idx_map = NULL;
    int idx = 0;
    for (int i = 0; i < inorderSize; i++) {
        insertHashTable(inorder[i], idx++);
    }

    return helper(0, inorderSize - 1, inorder, postorder);
}

