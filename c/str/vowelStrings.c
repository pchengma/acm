// LeetCode: 2586. Count the Number of Vowel Strings in Range (Easy)
bool IsVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

int vowelStrings(char **words, int wordsSize, int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; i++) {
        int len = strlen(words[i]);
        if (IsVowel(words[i][0]) && IsVowel(words[i][len - 1])) {
            ans++;
        }
    }
    return ans;
}