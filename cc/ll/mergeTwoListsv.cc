// LeetCode: 21. Merge Two Sorted Lists (Easy)
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *oneptr = list1;
        ListNode *twoptr = list2;
        ListNode *ans = new ListNode();
        ListNode *ansptr = ans;
        while (oneptr && twoptr) {
            if (oneptr->val <= twoptr->val) {
                ansptr->next = oneptr;
                oneptr = oneptr->next;
            } else if (twoptr->val < oneptr->val) {
                ansptr->next = twoptr;
                twoptr = twoptr->next;
            }
            ansptr = ansptr->next;
        }
        ansptr->next = oneptr ? oneptr : twoptr;
        ans = ans->next;
        return ans;
    }
};