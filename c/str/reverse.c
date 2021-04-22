#include <stdio.h>
#include <string.h>

void reverse(char* s) {
    char* stk = (char*) malloc(sizeof(char) * strlen(s) + 1);
    int top = -1;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ')') {
            int sub_len = 0;

            while (s[top] != '(' && top > -1) {
                ++sub_len;
                --top;
            }
            memcpy(stk, s + top + 1, sub_len);
            --top;
            while (sub_len > 0) {
                s[++top] = stk[--sub_len];
            }
        }
        else {
            s[++top] = s[i];
        }
    }
    free(stk);
    s[top + 1] = '\0';
}

int main() {
    char str[10001];

    scanf("%s", str);

    reverse(str);

    puts(str);

    return 0;
}
