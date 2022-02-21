// LeetCode: 169. Majority Element (Easy)
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        map<int, int> hash_tbl;

        for (auto &i: nums) {
            ++hash_tbl[i];
            if (hash_tbl[i] > nums.size() / 2) {
                return i;
            }
        }

        return 0;
    }
};