// LeetCode: 31. Next Permutation (Medium)
class Solution {
public:
    void reverse(vector<int> &nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }

    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;

        while (i >= 0 && nums[i + 1] <= nums[i]) {
            --i;
        }

        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }

        reverse(nums, i + 1);
    }
};