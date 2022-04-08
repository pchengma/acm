// LeetCode: 703. Kth Largest Element in a Stream (Easy)
class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> heap;

    KthLargest(int k, vector<int> &nums) {
        K = k;
        for (auto &i: nums) {
            heap.push(i);
        }
    }

    int add(int val) {
        heap.push(val);
        while (heap.size() > K) {
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */