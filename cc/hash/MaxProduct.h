// LeetCode: 318. Maximum Product of Word Lengths (Medium)
class MaxProduct {
public:
    int maxProduct(vector <string> &words) {
        vector<int> bitMasks;

        for (auto &str: words) {
            int bitMask = 0;

            for (auto &c: str) {
                bitMask |= 1 << (c - 'a');
            }

            bitMasks.push_back(bitMask);
        }

        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((bitMasks[i] & bitMasks[j]) > 0) {
                    continue;
                }

                int product = words[i].size() * words[j].size();
                ans = max(ans, product);
            }
        }

        return ans;
    }
};