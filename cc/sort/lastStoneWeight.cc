// LeetCode: 1046. Last Stone Weight (Easy)
class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            if (stones[stones.size() - 1] == stones[stones.size() - 2]) {
                stones.pop_back();
                stones.pop_back();
            } else {
                stones[stones.size() - 2] = stones[stones.size() - 1] - stones[stones.size() - 2];
                stones.pop_back();
            }
        }

        return stones.size() > 0 ? stones[0] : 0;
    }
};