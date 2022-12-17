// LeetCode: 150. Evaluate Reverse Polish Notation (Medium)
#define INIT_CAPACITY 8
#define INCREMENT 2

int isNumber(const char *str) {
    char ch = str[0];
    return !(ch == '+' || !strcmp(str, "-") || ch == '*' || ch == '/');
}

int evalRPN(char **tokens, int tokensSize) {
    unsigned sz = 0, capacity = INIT_CAPACITY;
    long *stk = (long *) malloc(sizeof(long) * capacity);
    long x = 0L, y = 0L;
    for (int i = 0; i < tokensSize; ++i) {
        char *token = tokens[i];
        if (isNumber(token)) {
            if (sz == capacity) {
                long *new_stk = (long *) realloc(stk, sizeof(long) * capacity * INCREMENT);
                if (NULL == new_stk) exit(-1);
                stk = new_stk;
                capacity *= INCREMENT;
            }
            stk[sz++] = atol(token);
        } else {
            y = stk[--sz];
            x = stk[--sz];
            switch (token[0]) {
                case '+':
                    stk[sz++] = x + y;
                    break;
                case '-':
                    stk[sz++] = x - y;
                    break;
                case '*':
                    stk[sz++] = x * y;
                    break;
                case '/':
                    stk[sz++] = x / y;
                    break;
                default:;
            }
        }
    }
    return stk[sz - 1];
}
