// LeetCode: 109. Convert Sorted List to Binary Search Tree (Medium)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode* getMedian(struct ListNode* left, struct ListNode* right) {
    struct ListNode* fast = left;
    struct ListNode* slow = left;
    while (fast != right && fast->next != right) {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

struct TreeNode* buildTree(struct ListNode* left, struct ListNode* right) {
    if (left == right) {
        return NULL;
    }
    struct ListNode* mid = getMedian(left, right);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = mid->val;
    root->left = root->right = NULL;
    root->left = buildTree(left, mid);
    root->right = buildTree(mid->next, right);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    return buildTree(head, NULL);
}

