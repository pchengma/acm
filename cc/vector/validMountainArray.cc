// LeetCode: 941. Valid Mountain Array (Easy)
class Solution {
public:
    bool validMountainArray(vector<int> &arr) {
        int i = 0;

        // walk up
        while (i + 1 < arr.size() && arr[i] < arr[i + 1]) {
            ++i;
        }

        // peak can't be first or last
        if (i == 0 || i == arr.size() - 1) {
            return false;
        }

        // walk down
        while (i + 1 < arr.size() && arr[i] > arr[i + 1]) {
            ++i;
        }

        return i == arr.size() - 1;
    }
};