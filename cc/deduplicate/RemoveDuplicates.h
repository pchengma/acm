// LeetCode: 26. Remove Duplicates from Sorted Array (Easy)
class RemoveDuplicates {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0, j = 1;

        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                j++;
            } else {
                i++;
                nums[i] = nums[j];
                j++;
            }
        }

        return i + 1;
    }
};