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
#include <iostream>

using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode *head) {
        ListNode *tmp = head;
        int len = 0;
        while (tmp != NULL) {
            ++len;
            tmp = tmp->next;
        }

        int res = 0;
        int cnt = 0;
        while (head != NULL) {
            res += head->val * (1 << (len - 1 - cnt));
            head = head->next;
            ++cnt;
        }
        return res;
    }
};