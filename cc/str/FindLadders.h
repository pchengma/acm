// LeetCode: 126. Word Ladder II (Hard)
class Solution {
public:
    vector <vector<string>> findLadders(string beginWord, string endWord, vector <string> &wordList) {
        wordList.insert(wordList.begin(), beginWord);
        for (int i = 1; i < wordList.size(); i++) {
            if (wordList[i].compare(wordList[0]) == 0) {
                wordList[i] = wordList.back();
                wordList.pop_back();
                break;
            }
        }
        unordered_map<string, int> word_to_index;
        for (int i = 0; i < wordList.size(); i++) {
            word_to_index.insert({wordList[i], i});
        }
        if (word_to_index.count(endWord) == 0) return {};

        vector <vector<int>> edges(word_to_index.size());
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < wordList.size(); j++) {
                if (i == j) continue;
                if (differ_by_one(wordList[i], wordList[j])) {
                    edges[i].push_back(j);
                }
            }
        }
        // BFS search, lets start from node=0, 
        int start_node = 0, target_node = word_to_index[endWord];
        vector<int> marked(wordList.size(), INT_MAX);
        marked[start_node] = 0;
        queue<int> units;
        units.push(start_node);
        int r = 0;
        int min_step = INT_MAX;
        while (!units.empty()) {
            int round_size = units.size();
            for (int i = 0; i < round_size; i++) {
                int node = units.front();
                units.pop();
                if (node == target_node) {
                    min_step = min(min_step, r);
                }
                for (int j = 0; j < edges[node].size(); j++) {
                    int update_node = edges[node][j];
                    if (r + 1 < marked[update_node]) {
                        marked[update_node] = r + 1;
                        units.push(update_node);
                    }
                }
            }
            r++;
        }
        // printf("min_step = %d\n", min_step);
        if (min_step == INT_MAX) {
            return {};
        }
        queue <vector<string>> seqs;
        seqs.push({wordList[target_node]});
        r = min_step;
        while (r > 0) {
            int round_size = seqs.size();
            for (int i = 0; i < round_size; i++) {
                vector <string> seq = seqs.front();
                seqs.pop();
                string back = seq.back();
                int node = word_to_index[back];
                for (int j = 0; j < edges[node].size(); j++) {
                    int update_node = edges[node][j];
                    if (marked[update_node] == r - 1) {
                        seq.push_back(wordList[update_node]);
                        seqs.push(seq);
                        seq.pop_back();
                    }
                }
            }
            r--;
        }
        vector <vector<string>> result;
        while (!seqs.empty()) {
            vector <string> seq = seqs.front();
            seqs.pop();
            reverse(seq.begin(), seq.end());
            result.push_back(seq);
        }
        return result;
    }

    bool differ_by_one(string a, string b) {
        int differ = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                differ += 1;
                if (differ > 1) return false;
            }
        }
        return differ == 1;
    }
};