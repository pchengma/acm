// LeetCode: 71. Simplify Path (Medium)
class Solution {
public:
    string simplifyPath(string path) {
        stack <string> s;

        int i = 1;
        string ans = "";
        string file_name = "";

        if (path[path.length() - 1] != '/') {
            path += "/";
        }

        while (i < path.length()) {
            if (path[i] == '/') {
                if (file_name == "" || file_name == ".") {

                } else if (file_name == "..") {
                    if (!s.empty()) {
                        s.pop();
                    }
                } else {
                    s.push(file_name);
                }

                file_name = "";
            } else {
                file_name.push_back(path[i]);
            }

            ++i;
        }

        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }

        if (ans.length() == 0) {
            ans = "/";
        }

        return ans;
    }
};