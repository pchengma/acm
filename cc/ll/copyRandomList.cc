// LeetCode: 138. Copy List with Random Pointer (Medium)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map < Node * , Node * > mp = {{nullptr, nullptr}};

        for (Node *node = head; node; node = node->next) {
            mp[node] = new Node(node->val);
        }

        for (Node *node = head; node; node = node->next) {
            mp[node]->next = mp[node->next];
            mp[node]->random = mp[node->random];
        }

        return mp[head];
    }
};