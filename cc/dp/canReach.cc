// LeetCode: 1306. Jump Game III (Medium)
class Solution{
        public:
        bool canReach(vector<int>& arr, int start) {
            // if arr[start] is 0, return true
            if (!arr[start]) {
                return true;
            }

            // if already visited that value, return false
            if (arr[start] == -1) {
                return false;
            }

            // left and right
            int left = start - arr[start], right = start + arr[start];

            // visited index
            arr[start] = -1;

            return right = (right < arr.size() && canReach(arr, right)) || (left >= 0 && canReach(arr, left));
        }
};