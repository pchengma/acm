// LeetCode: 92. Reverse Linked List II (Medium)
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
class ReverseBetween {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right) {
            return head;
        }

        ListNode *curr = head;
        ListNode *rest = head;
        ListNode *next;
        ListNode *ptr;
        ListNode *temp;
        int count = 1;

        while (count < right) {
            if (count < left) {
                temp = curr;
                curr = curr->next;
            }
            rest = rest->next;
            count++;
        }

        if (rest->next == NULL) {
            ptr = NULL;
        } else {
            ptr = rest->next;
        }

        while (left <= right) {
            next = curr->next;
            curr->next = ptr;
            ptr = curr;
            curr = next;
            left++;
        }

        if (!temp) {
            return ptr;
        }

        temp->next = ptr;
        return head;
    }
};