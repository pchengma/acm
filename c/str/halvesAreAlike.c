// LeetCode: 1704. Determine if String Halves Are Alike (Easy)
bool halvesAreAlike(char *s) {
    int len = strlen(s);
    int left = 0, right = 0, i;
    for (i = 0; i < len / 2; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            left++;
        }
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            left++;
        }
    }
    for (; i < len; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            right++;
        }
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            right++;
        }
    }
    return left == right;
}