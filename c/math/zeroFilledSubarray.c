// LeetCode: 2348. Number of Zero-Filled Subarrays
long long zeroFilledSubarray(int* nums, int numsSize){
    long long count = 0, totalOfSubArr = 0, ans = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            ++count;
        } else {
            totalOfSubArr = (1 + count) * count / 2;
            ans += totalOfSubArr;
            totalOfSubArr = 0;
            count = 0;
        }
    }
    totalOfSubArr = (1 + count) * count / 2;
    ans += totalOfSubArr;
    return ans;
}
