// LeetCode: 1647. Minimum Deletions to Make Character Frequencies Unique (Medium)
class MinDeletions {
public:
    int minDeletions(string s) {
        vector<int> frequency(26, 0);
        for (char c: s) {
            frequency[c - 'a']++;
        }

        int deleteCount = 0;
        unordered_set<int> seenFrequencies;
        for (int i = 0; i < 26; i++) {
            while (frequency[i] && seenFrequencies.find(frequency[i]) != seenFrequencies.end()) {
                frequency[i]--;
                deleteCount++;
            }
            seenFrequencies.insert(frequency[i]);
        }

        return deleteCount;
    }
};