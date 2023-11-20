// LeetCode: 53. Maximum Subarray (Medium)
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = nums[0];
        int max = sum;
        // if sum now is negative, discard sum as it will only make max smaller
        if (sum < 0) {
            sum = 0;
        }

        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > max) {
                max = sum;
            }

            // if sum now is negative, discard sum as it will only make max smaller
            if (sum < 0) {
                sum = 0;
            }
        }

        return max;
    }
};
