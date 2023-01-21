// LeetCode: 93. Restore IP Addresses (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SEG_COUNT 4
int segments[SEG_COUNT];
char **ans;
int ans_len;

void dfs(char *s, int segId, int segStart) {
    int len_s = strlen(s);
    if (segId == SEG_COUNT) {
        if (segStart == len_s) {
            char *ipAddr = (char *) malloc(sizeof(char) * (len_s + 4));
            int add = 0;
            for (int i = 0; i < SEG_COUNT; ++i) {
                int number = segments[i];
                if (number >= 100) {
                    ipAddr[add++] = number / 100 + '0';
                }
                if (number >= 10) {
                    ipAddr[add++] = number % 100 / 10 + '0';
                }
                ipAddr[add++] = number % 10 + '0';
                if (i != SEG_COUNT - 1) {
                    ipAddr[add++] = '.';
                }
            }
            ipAddr[add] = 0;
            ans = realloc(ans, sizeof(char *) * (ans_len + 1));
            ans[ans_len++] = ipAddr;
        }
        return;
    }

    if (segStart == len_s) {
        return;
    }
    if (s[segStart] == '0') {
        segments[segId] = 0;
        dfs(s, segId + 1, segStart + 1);
    }

    int addr = 0;
    for (int segEnd = segStart; segEnd < len_s; ++segEnd) {
        addr = addr * 10 + (s[segEnd] - '0');
        if (addr > 0 && addr <= 0xFF) {
            segments[segId] = addr;
            dfs(s, segId + 1, segEnd + 1);
        } else {
            break;
        }
    }
}

char **restoreIpAddresses(char *s, int *returnSize) {
    ans = (char **) malloc(0);
    ans_len = 0;
    dfs(s, 0, 0);
    (*returnSize) = ans_len;
    return ans;
}
