// LeetCode: 43. Multiply Strings (Medium)
char *addStrings(char *num1, char *num2) {
    int i = strlen(num1) - 1, j = strlen(num2) - 1, add = 0;
    char *ans = malloc(sizeof(char) * (i + j + 5));
    int ansLen = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ans[ansLen++] = result % 10;
        add = result / 10;
        i--;
        j--;
    }
    for (int i = 0; i < ansLen / 2; i++) {
        char t = ans[i];
        ans[i] = ans[ansLen - 1 - i];
        ans[ansLen - 1 - i] = t;
    }
    for (int i = 0; i < ansLen; i++) {
        ans[i] += '0';
    }
    ans[ansLen++] = 0;
    return ans;
}

char *multiply(char *num1, char *num2) {
    int m = strlen(num1), n = strlen(num2);
    char *ans = malloc(sizeof(char) * 2);
    ans[0] = '0', ans[1] = 0;
    if ((m == 1 && num1[0] == '0') || (n == 1 && num2[0] == '0')) {
        return ans;
    }
    for (int i = n - 1; i >= 0; i--) {
        char *curr = malloc(sizeof(char) * (n + m + 5));
        int currLen = 0;
        int add = 0;
        for (int j = n - 1; j > i; j--) {
            curr[currLen++] = 0;
        }
        int y = num2[i] - '0';
        for (int j = m - 1; j >= 0; j--) {
            int x = num1[j] - '0';
            int product = x * y + add;
            curr[currLen++] = product % 10;
            add = product / 10;
        }
        while (add != 0) {
            curr[currLen++] = add % 10;
            add /= 10;
        }
        for (int i = 0; i < currLen / 2; i++) {
            char t = curr[i];
            curr[i] = curr[currLen - 1 - i];
            curr[currLen - 1 - i] = t;
        }
        for (int i = 0; i < currLen; i++) {
            curr[i] += '0';
        }
        curr[currLen++] = 0;
        char *tmp = addStrings(ans, curr);
        free(ans), free(curr);
        ans = tmp;
    }
    return ans;
}
