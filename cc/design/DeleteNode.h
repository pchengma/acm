// LeetCode: 237. Delete Node in a Linked List (Medium)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class DeleteNode {
public:
    void deleteNode(ListNode *node) {
        ListNode *next = node->next;
        *node = *next;
        delete next;
    }
};