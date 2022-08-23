// LeetCode: 234. Palindrome Linked List (Easy)
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
class IsPalindrome {
public:
    bool isPalindrome(ListNode *head) {
        vector<int> vals;
        while (head != NULL) {
            vals.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < vals.size() / 2; ++i) {
            if (vals[i] != vals[vals.size() - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};