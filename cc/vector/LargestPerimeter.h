// LeetCode: 976. Largest Perimeter Triangle (Easy)
class Solution {
public:
    int largestPerimeter(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i = nums.size() - 1;
        while (i >= 2) {
            int s1 = nums[i];
            int s2 = nums[i - 1];
            int s3 = nums[i - 2];
            if (s1 < s2 + s3) {
                return s1 + s2 + s3;
            }
            i--;
        }

        return 0;
    }
};