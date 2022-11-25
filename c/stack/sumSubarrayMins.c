// LeetCode: 907. Sum of Subarray Minimums (Meidum)
int sumSubarrayMins(int *arr, int arrSize) {
    int *stack = malloc(sizeof(int) * arrSize);
    int top = -1;

    int *prev = malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++) {
        prev[i] = -1;
    }

    for (int i = 0; i < arrSize; i++) {
        if (top > -1) {
            if (arr[i] <= arr[stack[top]]) {
                while (top > -1 && arr[i] <= arr[stack[top]]) {
                    top--;
                }
                if (top > -1) {
                    prev[i] = stack[top];
                }
                top++;
                stack[top] = i;
            } else {
                prev[i] = stack[top];
                top++;
                stack[top] = i;
            }
        } else {
            top++;
            stack[top] = i;
        }
    }

    long long sum = 0;
    for (int i = 0; i < arrSize; i++) {
        if (prev[i] != -1) {
            prev[i] = prev[prev[i]] + (i - prev[i]) * arr[i];
            sum = sum + prev[i];
        } else {
            prev[i] = (i + 1) * arr[i];
            sum = sum + prev[i];
        }
        sum = sum % 1000000007;
    }

    return sum;
}