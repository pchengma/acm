// LeetCode: 973. K Closest Points to Origin (Medium)
class Solution {
public:
    vector <vector<int>> kClosest(vector <vector<int>> &points, int k) {
        vector <vector<int>> result(k);

        priority_queue <vector<int>> maxHeap;

        for (auto &p: points) {
            maxHeap.push({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        for (int i = 0; i < k; ++i) {
            result[i] = {maxHeap.top()[1], maxHeap.top()[2]};
            maxHeap.pop();
        }

        return result;
    }
};