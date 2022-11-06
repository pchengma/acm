// LeetCode: 899. Orderly Queue (Hard)
int compare(const void *a, const void *b) {
    return *(char *) a - *(char *) b;
}

char *orderlyQueue(char *s, int k) {
    int len = strlen(s);
    if (k == 1) {
        char temp;
        char *result = (char *) malloc(sizeof(char) * len + 1);
        strcpy(result, s);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len - 1; j++) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
            if (strcmp(result, s) > 0) strcpy(result, s);
        }
        return result;
    } else {
        qsort(s, len, sizeof(char), compare);
        return s;
    }
}