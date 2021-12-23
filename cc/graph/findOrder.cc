// LeetCode: 210. Course Schedule II (Medium)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector <vector<int>> &prerequisites) {
        vector <vector<int>> G(numCourses);

        vector<int> ans, indegree(numCourses);

        for (auto &pre: prerequisites) {
            G[pre[1]].push_back(pre[0]), indegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (size(q)) {
            auto cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (auto nextCourse: G[cur]) {
                if (--indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        if (size(ans) == numCourses) {
            return ans;
        }
        return {};
    }
};