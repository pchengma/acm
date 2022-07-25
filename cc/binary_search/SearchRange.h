// LeetCode: 34. Find First and Last Position of Element in Sorted Array (Medium)
class SearchRange {
public:
    int getIndex(vector<int> &nums, int target, bool getFirst) {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (getFirst) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> v(2, -1);

        int first = getIndex(nums, target, true);
        if (first == -1) {
            return v;
        }

        int last = getIndex(nums, target, false);

        v[0] = first;
        v[1] = last;
        return v;
    }
};