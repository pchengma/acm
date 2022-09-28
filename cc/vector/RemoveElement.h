// LeetCode: 27. Remove Element (Easy)
class RemoveElement {
public:
    int removeElement(vector<int> &nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            auto it = nums.begin() + i;
            if (nums[i] == val) {
                nums.erase(it);
                i--;
            }
        }
        return nums.size();
    }
};