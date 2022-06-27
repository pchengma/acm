// LeetCode: 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers (Medium)
class MinPartitions {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};