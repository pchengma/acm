// LeetCode: 895. Maximum Frequency Stack (Hard)
class FreqStack {
public:
    map<int, int> freq;
    map<int, stack<int>> group;
    int max_freq;

    FreqStack() {
        max_freq = 0;
    }

    void push(int val) {
        int f = freq[val] + 1;
        freq[val] = f;
        if (f > max_freq) {
            max_freq = f;
        }
        group[f].push(val);
    }

    int pop() {
        int x = group[max_freq].top();
        group[max_freq].pop();
        --freq[x];
        if (group[max_freq].size() == 0) {
            --max_freq;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */