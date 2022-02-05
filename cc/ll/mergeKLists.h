// LeetCode: 23. Merge k Sorted Lists (Hard)
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<int, vector<int>, greater<int>> temp;
        ListNode *answer = new ListNode(0);

        for (int i = 0; i < lists.size(); ++i) {
            ListNode *ptr = lists[i];
            while (ptr) {
                temp.push(ptr->val);
                ptr = ptr->next;
            }
        }

        ListNode *ptr2 = answer;
        while (!temp.empty()) {
            ListNode *number = new ListNode();
            number->val = temp.top();
            temp.pop();
            ptr2->next = number;
            ptr2 = ptr2->next;
        }

        return answer->next;
    }
};