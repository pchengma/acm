// LeetCode: 1461. Check If a String Contains All Binary Codes of Size K (Medium)
class HasAllCodes {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }

        const int n = s.size();
        const int mask = (1 << (k - 1)) - 1;

        long long num_binary_codes = 1 << k;
        long long sum = 0;
        long long correct_sum = (num_binary_codes * num_binary_codes - num_binary_codes) / 2;


        vector<bool> discovered(num_binary_codes, false);

        int cur_num = 0;

        int i = 0;

        for (; i < k; i++) {
            cur_num |= s[i] - '0';
            if (i != k - 1) {
                cur_num <<= 1;
            }
        }

        discovered[cur_num] = true;
        sum += cur_num;
        for (; i < n; i++) {
            cur_num &= mask;
            cur_num <<= 1;
            cur_num |= s[i] - '0';
            if (discovered[cur_num] == false) {
                sum += cur_num;
            }
            discovered[cur_num] = true;
        }

        return (sum == correct_sum) && discovered[0];
    }
};