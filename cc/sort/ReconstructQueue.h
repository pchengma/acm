// LeetCode: 406. Queue Reconstruction by Height (Medium)
class ReconstructQueue {
public:
    vector <vector<int>> reconstructQueue(vector <vector<int>> &people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector <vector<int>> ans;

        for (auto &person: people) {
            ans.insert(ans.begin() + person[1], person);
        }

        return ans;
    }
};