// LeetCode: 645. Set Mismatch (Easy)
class FindErrorNums {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();
        vector<int> tmp(n + 1, 0);
        vector<int> res;

        for (auto i: nums) {
            tmp[i]++;
        }

        for (int i = 1; i < n + 1; i++) {
            if (tmp[i] > 1)
                res.push_back(i);
        }
        for (int i = 1; i < n + 1; i++) {
            if (tmp[i] == 0)
                res.push_back(i);
        }

        return res;
    }
};