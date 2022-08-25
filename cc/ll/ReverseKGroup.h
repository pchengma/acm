// LeetCode: 25. Reverse Nodes in k-Group (Hard)
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
class ReverseKGroup {
public:

    int cnode = 0;
    int node = 0;

    int cnt(ListNode *head) {

        while (head) {
            node++;
            head = head->next;
        }

        return node;
    }

    ListNode *helper(ListNode *head, int k) {

        if (head == NULL) return head;

        if (node - cnode < k) return head;

        ListNode *prev, *curr, *next;
        prev = NULL;
        curr = head;
        next = NULL;

        int cnt = 0;

        while (cnt < k and curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        cnode += cnt;

        if (next) head->next = helper(next, k);

        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        cnt(head);
        return helper(head, k);
    }
};