// LeetCode: 587. Erect the Fence (Hard)
class OuterTrees {
public:
    struct point {
        int x, y;

        bool operator<(point &O) {
            if (O.x == x) return y < O.y;
            else return x < O.x;
        }

        bool operator==(point &O) {
            return (x == O.x && y == O.y);
        }
    };

    bool cw(point a, point b, point c) {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
    }

    bool ccw(point a, point b, point c) {
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
    }

    void convec_hull(vector <point> &p) {
        if (p.size() <= 2) return;

        sort(p.begin(), p.end());

        int i, n = p.size();

        point p1 = p[0], p2 = p[n - 1];
        vector <point> up, down;
        up.push_back(p1);
        down.push_back(p1);

        for (i = 1; i < n; i++) {
            if (i == n - 1 || !ccw(p1, p[i], p2)) {
                while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i])) {
                    up.pop_back();
                }
                up.push_back(p[i]);
            }
            if (i == n - 1 || !cw(p1, p[i], p2)) {
                while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i])) {
                    down.pop_back();
                }
                down.push_back(p[i]);
            }
        }

        p.clear();
        for (i = 0; i < up.size(); i++) {
            p.push_back(up[i]);
        }

        for (i = 0; i < down.size(); i++) {
            p.push_back(down[i]);
        }

        sort(p.begin(), p.end());
        p.resize(unique(p.begin(), p.end()) - p.begin());
    }

    vector <vector<int>> outerTrees(vector <vector<int>> &trees) {
        int n = trees.size();
        vector <point> p(n);

        for (int i = 0; i < trees.size(); i++) {
            p[i].x = trees[i][0];
            p[i].y = trees[i][1];
        }

        convec_hull(p);
        vector <vector<int>> ans;
        for (auto j: p) {
            ans.push_back({j.x, j.y});
        }
        return ans;
    }
};