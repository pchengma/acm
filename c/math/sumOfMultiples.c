// LeetCode: 2652. Sum Multiples (Easy)
int sumOfMultiples(int n) {
    int i;
    int ans = 0;
    for (i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
            ans += i;
        }
    }
    return ans;
}