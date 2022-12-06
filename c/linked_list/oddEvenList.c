// LeetCode: 328. Odd Even Linked List (Medium)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *oddEvenList(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *odd = head;
    struct ListNode *evenHead = head->next;
    struct ListNode *even = evenHead;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}