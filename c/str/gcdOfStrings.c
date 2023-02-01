// LeetCode: 1071. Greatest Common Divisor of Strings (Easy)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

char *gcdOfStrings(char *str1, char *str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    char *s1 = (char *) malloc(sizeof(char) * (len1 + len2 + 1)), *s2 = (char *) malloc(
            sizeof(char) * (len1 + len2 + 1)), *ans = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
    int i;
    strcpy(s1, str1);
    strcat(s1, str2);
    strcpy(s2, str2);
    strcat(s2, str1);
    if (strcmp(s1, s2) != 0) {
        return "";
    }
    int n = gcd(len1, len2);
    for (i = 0; i < n; i++) {
        ans[i] = str1[i];
    }
    ans[i] = '\0';
    return ans;
}
