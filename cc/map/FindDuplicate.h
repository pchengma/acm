// LeetCode: 609. Find Duplicate File in System (Medium)
class FindDuplicate {
public:
    vector <vector<string>> findDuplicate(vector <string> &paths) {
        unordered_map <string, vector<string>> m;
        for (const auto &path: paths) {
            stringstream ss(path);
            string folder, file;
            ss >> folder;
            while (ss >> file) {
                int i = 0;
                while (i < file.length() && '(' != file[i]) {
                    ++i;
                }
                m[file.substr(i + 1, file.length() - i - 2)].push_back(folder + '/' + file.substr(0, i));
            }
        }
        vector <vector<string>> ret;
        for (const auto &[content, files]: m) {
            if (files.size() > 1) {
                ret.push_back(move(files));
            }
        }
        return ret;
    }
};