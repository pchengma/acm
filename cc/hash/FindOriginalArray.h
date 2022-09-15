// LeetCode: 2007. Find Original Array From Doubled Array (Medium)
class FindOriginalArray {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        unordered_map<int, int> freq{};
        vector<int> result{};

        sort(changed.begin(), changed.end());

        for (int &val: changed) {
            freq[val]++;
        }

        for (int &val: changed) {
            if (freq[val] <= 0) {
                continue;
            }

            freq[val]--;

            if (freq[2 * val] > 0) {
                freq[2 * val]--;
                result.push_back(val);
                continue;
            }

            break;
        }

        if (2 * result.size() != changed.size()) {
            return {};
        }

        return result;
    }
};