// LeetCode: 86. Partition List (Medium)
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
class Partition {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *small = new ListNode();
        ListNode *other = new ListNode();

        ListNode *small_head = small;
        ListNode *other_head = other;

        while (head != NULL) {
            ListNode *tmp = new ListNode(head->val);
            if (head->val < x) {
                small->next = tmp;
                small = small->next;
            } else {
                other->next = tmp;
                other = other->next;
            }
            head = head->next;
        }

        small->next = other_head->next;
        return small_head->next;
    }
};