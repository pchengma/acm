// LeetCode: 224. Basic Calculator (Hard)
static char *p = NULL;

int readInteger() {
    assert(isdigit(*p));
    int d = 0;
    while (isdigit(*p)) {
        d *= 10;
        d += *p - '0';
        p++;
    }
    return d;
}

void skipSpaces() {
    while (isspace(*p)) {
        p++;
    }
}

int evalExpr();

int evalSimpleExpr() {
    int d = 0;
    if (isdigit(*p)) {
        d = readInteger();
    } else if (*p == '(') {
        p++;
        d = evalExpr();
        if (*p != ')') {
            fprintf(stderr, "unexpected char '%c', expects ')'", *p);
            exit(1);
        }
        p++;
    }
    return d;
}

int evalExpr() {
    skipSpaces();
    int d = evalSimpleExpr();
    while (true) {
        skipSpaces();
        if (*p == '\0') {
            break;
        }
        if (*p == ')') {
            break;
        }
        char op = *p;
        if (op != '+' && op != '-') {
            fprintf(stderr, "unexpect char '%c', expects '+' or '-'", op);
            exit(1);
        }
        p++;
        skipSpaces();
        if (op == '+') {
            d += evalSimpleExpr();
        } else {
            d -= evalSimpleExpr();
        }
    }
    return d;
}

int calculate(char *s) {
    p = s;
    return evalExpr();
}