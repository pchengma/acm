// LeetCode: 61. Rotate List (Medium)
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
    ListNode *rotateRight(ListNode *head, int k) {
        // If list is empty or there is only 1 element or rotate factor is 0, return original list:
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // there is more than 1 element
        int length = 1;

        // Init the last node:
        ListNode *last = new ListNode();

        // Iterate to find the last node and count length:
        last = head;
        while (last->next != NULL) {
            ++length;
            last = last->next;
        }

        // Take modulo in case k > length:
        k = k % length;
        // If k is 0 again, return original list:
        if (k == 0) {
            return head;
        }

        // Init the node before the newHead node (name it as secondLast):
        ListNode *secondLast = new ListNode();

        // Iterate to the corresponding position:
        secondLast = head;
        for (int i = 0; i < length - k - 1; ++i) {
            secondLast = secondLast->next;
        }

        // Init newHead node:
        ListNode *newHead = new ListNode();
        newHead = secondLast->next;

        // Set secondLast->next ptr as NULL:
        secondLast->next = NULL;

        // Point last->next to head:
        last->next = head;

        // Return rotated list:
        return newHead;
    }
};