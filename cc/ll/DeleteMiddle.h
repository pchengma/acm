// LeetCode: 2095. Delete the Middle Node of a Linked List (Medium)
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
class DeleteMiddle {
public:
    ListNode *middlePrev(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }

    ListNode *deleteMiddle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *curr = middlePrev(head);
        curr->next = curr->next->next;
        return head;
    }
};