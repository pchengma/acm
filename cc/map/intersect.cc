// LeetCode: 350. Intersection of Two Arrays II (Easy)
class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        unordered_map<int, int> hash_map1, hash_map2;
        for (auto i: nums1) {
            ++hash_map1[i];
        }
        for (auto i: nums2) {
            ++hash_map2[i];
        }
        for (auto i: hash_map1) {
            if (hash_map2[i.first] > 0) {
                for (int j = 0; j < min(hash_map2[i.first], i.second); ++j) {
                    res.push_back(i.first);
                }
            }
        }
        return res;
    }
};