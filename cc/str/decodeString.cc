// LeetCode: 394. Decode String (Medium)
class Solution {
public:
    string repeat(string str, int times) {
        string result = "";
        for (int i = 0; i < times; ++i) {
            result += str;
        }
        return result;
    }

    string decodeString(string s) {
        int i = 0;
        while (i < s.size()) {
            if (s[i] != ']') {
                ++i;
                continue;
            }

            int j = i;
            while (s[j] != '[') {
                --j;
            }

            string repeatLetters = s.substr(j + 1, i - j - 1);
            int k = j;
            --j;

            while ((j > 0) && (isdigit(s[j]))) {
                --j;
            }

            if (j != 0) {
                j++;
            }

            int repeatTimes = stoi(s.substr(j, k - j));

            s.replace(j, i - j + 1, repeat(repeatLetters, repeatTimes));

            i = j + repeatLetters.size() * repeatTimes;
        }
        return s;
    }
};