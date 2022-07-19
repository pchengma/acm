// LeetCode: 16. 3Sum Closest (Medium)
class ThreeSumClosest {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = nums[0] + nums[1] + nums[nums.size() - 1];
        sort(nums.begin(), nums.end());

        int s, e;
        for (int i = 0; i < nums.size() - 1; i++) {
            s = i + 1, e = nums.size() - 1;
            while (s < e) {
                int sum = nums[i] + nums[s] + nums[e];
                if (target > sum) {
                    s++;
                } else {
                    e--;
                }
                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
            }
        }
        return res;
    }
};