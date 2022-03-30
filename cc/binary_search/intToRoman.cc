// LeetCode: 12. Integer to Roman (Medium)
class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums({1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000});
        vector <string> strs({"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"});

        string ans;
        while (num > 0) {
            int val = leftMostValue(num);
            int idx = lowerBound(nums, val);

            if (nums[idx] > val) {
                --idx;
            }

            ans += strs[idx];
            num -= nums[idx];
        }

        return ans;
    }

    int leftMostValue(int num) {
        int b = 1;

        while (num / 10 > 0) {
            num /= 10;
            b *= 10;
        }

        return b * num;
    }

    int lowerBound(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};