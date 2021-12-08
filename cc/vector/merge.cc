// LeetCode: 88. Merge Sorted Array (Easy)
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        for (int i = 0; i < n; ++i) {
            int flag = 0;
            for (int j = 0; j < m + n && flag == 0; ++j) {
                if (nums2[i] <= nums1[j] || j > m + i - 1) {
                    nums1.insert(nums1.begin() + j, nums2[i]);
                    flag = 1;
                }
            }
        }
        nums1.erase(nums1.begin() + m + n, nums1.end());
    }
};