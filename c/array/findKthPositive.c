// LeetCode: 1539. Kth Missing Positive Number (Easy)
int findKthPositive(int* arr, int arrSize, int k){
    int i = 0, missNumCnt = 0, arrPos = 0;
    
    while (missNumCnt != k) {
        if (arrPos < arrSize && i + 1 == arr[arrPos]) {
            arrPos++;
        } else {
            missNumCnt++;
        }
        i++;
    }

    return i;
}
