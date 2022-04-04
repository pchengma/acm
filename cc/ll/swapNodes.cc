// LeetCode: 1721. Swapping Nodes in a Linked List (Medium)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }


        ListNode *tmp_node = head;
        while (--k) {
            tmp_node = tmp_node->next;
        }

        ListNode *node_a = tmp_node;
        ListNode *node_b = head;
        while (tmp_node->next) {
            node_b = node_b->next;
            tmp_node = tmp_node->next;
        }

        swap(node_a->val, node_b->val);

        return head;
    }
};