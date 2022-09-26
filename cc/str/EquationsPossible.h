// LeetCode: 990. Satisfiability of Equality Equations (Medium)
class EquationsPossible {
public:
    static bool cmp(string &a, string &b) {
        if (a[1] == '=' && b[1] == '!') {
            return true;
        }
        return false;
    }

    void makePair(int &s, vector<int> &p, vector<int> &sz) {
        p[s] = s;
        sz[s] = 1;
    }

    int doFind(int &u, vector<int> &p) {
        if (u == p[u]) {
            return u;
        }
        return p[u] = doFind(p[u], p);
    }

    void doUnion(int &u, int &v, vector<int> &p, vector<int> &s) {
        int a = doFind(u, p);
        int b = doFind(v, p);
        if (a != b) {
            if (s[a] < s[b]) {
                swap(a, b);
            }
            p[b] = a;
            s[a] += s[b];
        }
    }

    bool equationsPossible(vector <string> &equations) {
        vector<int> p(26);
        vector<int> s(26);
        sort(equations.begin(), equations.end(), cmp);

        for (int i = 0; i < 26; i++) {
            makePair(i, p, s);
        }
        int a, b, c;
        for (auto &i: equations) {
            a = i[0] - 'a';
            b = i[1];
            c = i[3] - 'a';
            if (b == '=') {
                doUnion(a, c, p, s);
            } else {
                if (doFind(a, p) == doFind(c, p)) {
                    return false;
                }
            }
        }
        return true;
    }
};