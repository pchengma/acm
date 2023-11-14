// LeetCode: 202. Happy Number (Easy)
bool isHappy(int n) {
    short _n;
    while (n != 0 && n != 1 && n != 4 && n != 16 && n != 37 && n != 58
           && n != 89 && n != 145 && n != 42 && n != 20) {
        _n = 0;
        while (n) {
            _n = _n + pow(n % 10, 2);
            n = n / 10;
        }
        n = _n;
    }
    if (n == 1) {
        return 1;
    }
    return 0;
}
