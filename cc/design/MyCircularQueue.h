// LeetCode: 622. Design Circular Queue (Medium)
class MyCircularQueue {
public:
    MyCircularQueue(int k) :
            data{new int[k]},
            cap{k} {
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data.get()[write++ % cap] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        ++read;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data.get()[read % cap];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data.get()[(write - 1) % cap];
    }

    bool isEmpty() {
        return write == read;
    }

    bool isFull() {
        return write - read == cap;
    }

private:
    std::unique_ptr<int[]> data;
    int read = 0;
    int write = 0;
    int cap = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */