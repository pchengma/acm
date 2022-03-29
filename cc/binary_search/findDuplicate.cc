// LeetCode: 287. Find the Duplicate Number (Medium)
class Solution {
public:

    int findDuplicate(vector<int> &nums) {
        auto small_or_equal = [&](int cur) {
            int count = 0;
            for (auto &num: nums) {
                if (num <= cur) {
                    ++count;
                }
            }
            return count;
        };

        int low = 1, high = nums.size();
        int duplicate = -1;
        while (low <= high) {
            int cur = (low + high) / 2;

            if (small_or_equal(cur) > cur) {
                duplicate = cur;
                high = cur - 1;
            } else {
                low = cur + 1;
            }
        }

        return duplicate;
    }
};