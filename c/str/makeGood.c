// LeetCode: 1544. Make The String Great (Easy)
int badPair(char ch1, char ch2) {
    return ch1 != ch2 && tolower(ch1) == tolower(ch2);
}

char *makeGood(char *s) {
    const char *in = s;
    char *out = s;

    for (; *in != '\0'; ++in) {
        if (out > s && badPair(*(out - 1), *in)) {
            --out;
        } else {
            *(out++) = *in;
        }
    }

    *out = '\0';

    return s;
}