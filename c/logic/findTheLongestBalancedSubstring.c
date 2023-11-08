// LeetCode: 2609. Find the Longest Balanced Substring of a Binary String (Easy)
int findTheLongestBalancedSubstring(char *s) {
    int max = 0;
    int zeroCnt = 0;
    int oneCnt = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '0') {
            if (oneCnt > 0) {
                zeroCnt = 0;
                oneCnt = 0;
            }
            zeroCnt++;
        } else if (s[i] == '1') {
            oneCnt++;
            if (oneCnt <= zeroCnt) {
                if (max < oneCnt * 2) {
                    max = oneCnt * 2;
                }
            }
        }
    }
    return max;
}