// LeetCode: 204. Count Primes (Medium)
int countPrimes(int n) {
    if (n < 2) {
        return 0;
    }
    int isPrime[n];
    int primes[n], primesSize = 0;
    memset(isPrime, 0, sizeof(isPrime));
    for (int i = 2; i < n; ++i) {
        if (!isPrime[i]) {
            primes[primesSize++] = i;
        }
        for (int j = 0; j < primesSize && i * primes[j] < n; ++j) {
            isPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return primesSize;
}
