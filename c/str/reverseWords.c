// LeetCode: 151. Reverse Words in a String (Medium)
void addWord(char **x, int *len, char *w, int wl) {
    if (wl <= 0) {
        return;
    }
    int space = 0;
    if (*len > 0) {
        space = 1;
    }
    *x = realloc(*x, sizeof(char) * (*len + wl + 1 + space));
    if (space) {
        (*x)[*len] = ' ';
    }
    memcpy(*x + *len + space, w, wl);
    *len += wl + space;
    (*x)[*len] = '\0';
    return;
}

char *reverseWords(char *s) {
    int len = 0;
    char *x = malloc(sizeof(char) * (len + 1));
    x[len] = '\0';
    int slen = strlen(s);
    int start = -1;
    for (int i = slen - 1; i >= 0; i--) {
        if (isspace(s[i])) {
            if (start > 0) {
                addWord(&x, &len, s + i + 1, start - i);
                start = -1;
            }
            continue;
        }
        if (start < 0) {
            start = i;
        }
    }
    if (start >= 0) {
        addWord(&x, &len, s, start - 0 + 1);
    }
    return x;
}