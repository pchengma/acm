// LeetCode: 912. Sort an Array (Medium)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 */
void mergeSort (int* nums, int p, int r) {
    if (p >= r) {
      return;
    }
  
    int q;
    q = (p+r)/2;
  
    mergeSort(nums,p,q);
    mergeSort(nums, q+1, r);
    merge(nums,p,q,r);
}

void merge (int* nums, int p, int q, int r) {
    int *temp;
    int i , j , k ;

    temp = (int *)malloc((r-p+1) * sizeof(int));
  
    if (!temp) {
      abort();
    }
  
    for (i = p,j = q+1,k=0; i<=q && j<= r;) {
      if (nums[i] <= nums[j]) {
        temp[k++] = nums[i++];
      } else {
        temp[k++] = nums[j++];
      }
    
    }

    if (i == q+1) {
      for (; j <= r;) {
        temp[k++] = nums[j++];
      }
    
    } else {
      for (; i <= q; ) {
        temp[k++] = nums[i++];
      }
    }
  
    memcpy(nums+p,temp,(r-p+1) * sizeof(int));
    free(temp);
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    mergeSort(nums,0,numsSize-1);
    *returnSize = numsSize;
    return nums;
}

