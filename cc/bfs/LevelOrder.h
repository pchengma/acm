// LeetCode: 429. N-ary Tree Level Order Traversal (Medium)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector <vector<int>> levelOrder(Node *root) {
        vector <vector<int>> res;
        if (!root)
            return res;

        queue < Node * > q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            vector<int> level;

            for (int i = 0; i < size; i++) {
                Node *frnt = q.front();
                q.pop();

                level.push_back(frnt->val);

                for (auto child: frnt->children)
                    q.push(child);
            }
            res.push_back(level);
        }

        return res;
    }
};