// LeetCode: 295. Find Median from Data Stream (Hard)
class MedianFinder {
public:
    priority_queue<double> max_heap, min_heap;

    MedianFinder() {

    }

    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(-max_heap.top());
        max_heap.pop();

        if (min_heap.size() > max_heap.size()) {
            max_heap.push(-min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        return min_heap.size() < max_heap.size() ? max_heap.top() : (max_heap.top() - min_heap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */