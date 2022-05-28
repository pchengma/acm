// LeetCode: 268. Missing Number (Easy)
class MissingNumber {
public:
    int missingNumber(vector<int> &nums) {
        int ans = (1 + nums.size()) * nums.size() / 2;

        for (auto &i: nums) {
            ans -= i;
        }

        return ans;
    }
};