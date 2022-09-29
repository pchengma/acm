// LeetCode: 658. Find K Closest Elements (Medium)
class FindClosestElements {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        auto cmp = [&](const int &a, const int &b) {
            int abs_val_one = abs(a - x);
            int abs_val_two = abs(b - x);

            bool val_one = abs_val_one < abs_val_two;
            bool val_two = a < b && abs_val_one == abs_val_two;

            return val_one || val_two;
        };

        sort(arr.begin(), arr.end(), cmp);

        int itemsToPopOff = arr.size() - k;
        while (itemsToPopOff-- > 0)
            arr.pop_back();

        sort(arr.begin(), arr.end());

        return arr;
    }
};