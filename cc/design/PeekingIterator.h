// LeetCode: 284. Peeking Iterator (Medium)
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int *head;
    int pointer = 0, size;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        int n = nums.size();
        head = new int[n];
        for (auto c: nums) {
            head[pointer++] = c;
        }
        pointer = 0;
        size = nums.size();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return head[pointer];
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        return head[pointer++];
    }

    bool hasNext() const {
        return pointer < size;
    }
};