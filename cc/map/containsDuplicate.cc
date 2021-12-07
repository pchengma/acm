// LeetCode 217. Contains Duplicate (Easy)
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        /* Solution 1:
        unordered_map<int, int> hash_tbl;
        for (auto i : nums) {
            if (hash_tbl[i] == 1) {
                return true;
            }
            hash_tbl[i] = 1;
        }
        return false;
        */
        // Solution 2:
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};