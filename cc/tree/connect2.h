// LeetCode: 117. Populating Next Right Pointers in Each Node II (Medium)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Connect2 {
public:
    Node *connect(Node *root) {
        if (root == NULL) {
            return root;
        }

        int current_level = 0;
        queue < Node * > que;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n - 1; i++) {
                if (que.front()->left != NULL) {
                    que.push(que.front()->left);
                }

                if (que.front()->right != NULL) {
                    que.push(que.front()->right);
                }

                Node *tmp = que.front();
                que.pop();
                tmp->next = que.front();
            }
            que.front()->next = NULL;

            if (que.front()->left != NULL) {
                que.push(que.front()->left);
            }

            if (que.front()->right != NULL) {
                que.push(que.front()->right);
            }

            que.pop();
        }

        return root;
    }
};