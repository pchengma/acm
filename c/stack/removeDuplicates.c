// LeetCode: 1047. Remove All Adjacent Duplicates In String (Easy)
char *removeDuplicates(char *S) {
    char s[100000] = {*S}, *b = s, *p = S, *r = S;
    for (char *t = s; *++S; t < s || *S != *t ? *++t = *S : (*t-- = 0));
    while ((*p++ = *b++));
    return r;
}