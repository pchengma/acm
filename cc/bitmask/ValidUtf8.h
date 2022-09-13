// LeetCode: 393. UTF-8 Validation (Medium)
class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int count = 0;
        for (auto d: data) {
            if (count != 0) {
                if ((d & 0xC0) != 0x80) return false;
                count--;
            } else {
                if ((d & 0x80) == 0) continue;
                else if ((d & 0xE0) == 0xC0) count = 1;
                else if ((d & 0xF0) == 0xE0) count = 2;
                else if ((d & 0xF8) == 0xF0) count = 3;
                else return false;
            }
        }
        return (count == 0);
    }
};