// LeetCode: 290. Word Pattern (Easy)
bool wordPattern(char *pattern, char *s) {
    char *hashSetStr[26];

    for (int i = 0; i < 26; i++) {
        hashSetStr[i] = NULL;
    }

    const char target[2] = " ";
    int len = strlen(pattern);
    char *token = NULL;

    for (int i = 0; i < len; i++) {
        if (token == NULL) {
            token = strtok(s, target);
        } else {
            token = strtok(NULL, target);
            if (token == NULL) {
                return false;
            }
        }

        if (hashSetStr[pattern[i] - 'a'] == NULL) {
            hashSetStr[pattern[i] - 'a'] = token;
        } else {
            if (strcmp(hashSetStr[pattern[i] - 'a'], token) != 0) {
                return false;
            }
        }
    }
    token = strtok(NULL, target);
    if (token != NULL) {
        return false;
    }

    for (int i = 0; i < 26; i++) {
        if (hashSetStr[i] != NULL) {
            for (int j = i + 1; j < 26; j++) {
                if (hashSetStr[j] != NULL) {
                    if (strcmp(hashSetStr[i], hashSetStr[j]) == 0) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
