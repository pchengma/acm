#include <iostream>

using namespace std;

int str_str(string haystack, string needle) {
    int i, j;
    if (needle.length() == 0) {
        return 0;
    }

    if (needle.length() > haystack.length()) {
        return -1;
    }

    for (i = 0; i <= haystack.length() - needle.length(); ++i) {
        for (j = 0; j < needle.length(); ++j) {
            if (needle[j] != haystack[i + j]) {
                break;
            }
        }
        if (j == needle.length()) {
            return i;
        }
    }

    return -1;
}

string longest_palindrome(string s) {
    if (s.empty()) {
        return "";
    }

    if (s.size() == 1) {
        return s;
    }

    int start = 0, maxlen = 1;
    int i, low, high;

    for (i = 0; i < s.size(); ++i) {
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < s.size() && s[low] == s[high]) {
            if (high - low + 1 > maxlen) {
                maxlen = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
        low = i - 1;
        high = i;
        while (low >= 0 && high < s.size() && s[low] == s[high]) {
            if (high - low + 1 > maxlen) {
                maxlen = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
    }
    return s.substr(start, maxlen);
}

string shortest_palindrome(string s) {
    string s1 = s;

    reverse(s1.begin(), s1.end());

    int l = 0;
    while (s1 != s) {
        s.insert(l, 1, s1[l]);
        s1.insert(s1.size() - l, 1, s1[l]);
        l++;
    }
    return s1;
}

// test
int main() {
    string s = "abcbad";
    cout << longest_palindrome(s) << endl;
    cout << shortest_palindrome(s) << endl;

    return 0;
}