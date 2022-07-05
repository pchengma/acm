// LeetCode: 128. Longest Consecutive Sequence (Medium)
class LongestConsecutive {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());

        int longest_sequence = 0;

        for (int &num: nums) {
            if (nums_set.count(num - 1)) {
                continue;
            }
            int current_length = 1;
            while (nums_set.count(num + 1)) {
                num++;
                current_length++;
            }
            longest_sequence = max(longest_sequence, current_length);
        }

        return longest_sequence;
    }
};