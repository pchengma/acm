// LeetCode: 876. Middle of the Linked List (Easy)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *middleNode(struct ListNode *head) {
    int i = 0;
    int len = 0;

    struct ListNode *tmpNode = head;
    while (tmpNode != NULL) {
        len++;
        tmpNode = tmpNode->next;
    }

    int dst = len / 2 + 1;
    tmpNode = head;
    for (i = 0; i < dst - 1; i++) {
        tmpNode = tmpNode->next;
    }

    return tmpNode;
}