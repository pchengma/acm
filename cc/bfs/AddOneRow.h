// LeetCode: 623. Add One Row to Tree (Medium)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class AddOneRow {
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (depth == 1) {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }

        queue < TreeNode * > q;
        q.push(root);

        int count = 0;

        while (!q.empty()) {
            int s = q.size();
            count++;
            while (s--) {
                auto f = q.front();
                q.pop();

                if (count != depth - 1) {
                    if (f->left) {
                        q.push(f->left);
                    }
                    if (f->right) {
                        q.push(f->right);
                    }
                } else {
                    TreeNode *newNodeLeft = new TreeNode(val);
                    TreeNode *temp = f->left;
                    f->left = newNodeLeft;
                    newNodeLeft->left = temp;

                    TreeNode *newNodeRight = new TreeNode(val);
                    TreeNode *temp1 = f->right;
                    f->right = newNodeRight;
                    newNodeRight->right = temp1;
                }
            }
        }

        return root;
    }
};