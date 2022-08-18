// LeetCode: 1338. Reduce Array Size to The Half (Medium)
class Solution {
public:
    int minSetSize(vector<int> &arr) {
        vector<int> occurence(1e5 + 1, 0);
        for (auto a: arr) occurence[a]++;

        vector<int> store;
        for (int i = 0; i < 1e5 + 1; i++) {
            if (occurence[i]) store.push_back({occurence[i]});
        }

        sort(store.rbegin(), store.rend());

        int sizeOfArray = arr.size() / 2;
        int res = 0;
        while (sizeOfArray > 0) {
            sizeOfArray -= store[res++];
        }

        return res;
    }
};