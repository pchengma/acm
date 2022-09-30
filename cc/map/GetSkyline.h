// LeetCode: 218. The Skyline Problem (Hard)
class GetSkyline {
public:
    vector <vector<int>> getSkyline(vector <vector<int>> &buildings) {
        std::vector <std::pair<int, int>> coords;
        for (const auto &b: buildings) {
            coords.push_back({b[0], -b[2]});
            coords.push_back({b[1], b[2]});
        }

        std::sort(coords.begin(), coords.end());

        std::map<int, int> heights;

        std::vector <std::vector<int>> xs;

        heights[0] = 1;
        for (const auto &cur: coords) {
            if (cur.second < 0)
                ++heights[-cur.second];
            else if (--heights[cur.second] == 0)
                heights.erase(cur.second);

            int x = cur.first, y = heights.rbegin()->first;
            if (xs.size()) {
                int prev_x = xs.back()[0], prev_y = xs.back()[1];

                if (prev_y == y)
                    continue;

                if (prev_x == x)
                    xs.pop_back();
            }

            xs.push_back({x, y});
        }

        return xs;
    }
};