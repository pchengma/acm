#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_all_lower_case_alphabet(const char *sentence) {
    int i = 0;
    int cnt = 0;

    int flag[26] = {0};

    while (sentence[i] != '\0') {
        if (flag[sentence[i] - 'a'] == 0) {
            flag[sentence[i] - 'a'] = 1;
            ++cnt;
        }
        ++i;
    }

    if (cnt == 26) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char sentence[1000];

    gets(sentence);
    printf("%d\n", is_all_lower_case_alphabet(sentence));

    return 0;
}
