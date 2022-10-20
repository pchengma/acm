// LeetCode: 35. Search Insert Position (Easy)
class SearchInsert {
public:
    int searchInsert(vector<int> &nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};