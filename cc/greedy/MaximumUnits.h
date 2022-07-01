// LeetCode: 1710. Maximum Units on a Truck (Easy)
class MaximumUnits {
public:
    static bool comp(vector<int> a, vector<int> b) {
        if (a[1] != b[1]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    }

    int maximumUnits(vector <vector<int>> &boxTypes, int truckSize) {
        int ans = 0;

        sort(boxTypes.begin(), boxTypes.end(), comp);

        for (auto &it: boxTypes) {
            int x = it[0];
            int y = it[1];
            if (x <= truckSize) {
                ans += x * y;
                truckSize -= x;
            } else if (truckSize != 0) {
                ans += truckSize * y;
                break;
            }
        }

        return ans;
    }
};