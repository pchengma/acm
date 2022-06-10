// LeetCode: 3. Longest Substring Without Repeating Characters (Medium)
class LengthOfLongestSubstring {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> freq;

        int n = s.size();

        int L = 0;
        int R = 0;

        int ans = 0;

        while (R < n) {
            char right = s[R++];
            freq[right]++;

            while (freq[right] > 1) {
                char left = s[L++];
                freq[left]--;
            }

            ans = max(ans, R - L);
        }

        return ans;
    }
};