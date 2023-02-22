// LeetCode: 1011. Capacity To Ship Packages Within D Days (Medium)
int shipWithinDays(int *weights, int weightsSize, int days) {
    int left = 0, right = 0;
    for (int i = 0; i < weightsSize; i++) {
        left = fmax(left, weights[i]);
        right += weights[i];
    }
    while (left < right) {
        int mid = (left + right) / 2;
        int need = 1, cur = 0;
        for (int i = 0; i < weightsSize; i++) {
            if (cur + weights[i] > mid) {
                ++need;
                cur = 0;
            }
            cur += weights[i];
        }
        if (need <= days) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
