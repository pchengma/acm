// LeetCode: 83. Remove Duplicates from Sorted List (Easy)
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(-101);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr) {
            if (curr->val == prev->val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};