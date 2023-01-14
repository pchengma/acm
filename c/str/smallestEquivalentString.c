// LeetCode: 1061. Lexicographically Smallest Equivalent String (Medium)
char FindRoot(char *pcRoot, char cIndex) {
    if (cIndex == pcRoot[cIndex]) return cIndex;

    pcRoot[cIndex] = FindRoot(pcRoot, pcRoot[cIndex]);
    return pcRoot[cIndex];
}

char *smallestEquivalentString(char *s1, char *s2, char *baseStr) {
    char acRoot[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    while (*s1) {
        char cRoot1 = FindRoot(acRoot, *s1 - 'a'), cRoot2 = FindRoot(acRoot, *s2 - 'a');
        if (cRoot1 > cRoot2) {
            acRoot[cRoot1] = cRoot2;
        } else if (cRoot1 < cRoot2) {
            acRoot[cRoot2] = cRoot1;
        }

        s1++;
        s2++;
    }

    for (char i = 0; i < 26; i++) acRoot[i] = FindRoot(acRoot, i);
    for (char i = 0; i < 26; i++) acRoot[i] += 'a';

    char *pcTmp = baseStr;
    while (*pcTmp) {
        *pcTmp = acRoot[*pcTmp - 'a'];

        pcTmp++;
    }

    return baseStr;
}