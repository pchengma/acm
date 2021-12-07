#include <stdio.h>
#define N 99

// O(N)
int max_sub_array(int nums[N]) {
    int i;
    int max = 0, tmp = 0;
  
    for (i = 0; i < N; ++i) {
        if (max <= nums[i]) {
            max = nums[i];
        } else {
            if (max + nums[i] >= max) {
                max += nums[i];
            }
            tmp += nums[i];
        }
    }
  
    return max;
}

