// LeetCode: 40. Combination Sum II (Medium)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void combinationSum(int *candidate, int size, int target, int index, int *returnSize, int *columnSize, int *element,
                    int **output) {
    if (target == 0) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (element[i] == 1) {
                count++;
            }
        }
        output[*returnSize] = (int *) malloc(count * sizeof(int));
        columnSize[*returnSize] = 0;
        for (int i = 0; i < size; i++) {
            if (element[i] == 1) {
                output[*returnSize][columnSize[*returnSize]++] = candidate[i];
            }
        }
        (*returnSize)++;
    } else {
        for (int i = index; i < size && target - candidate[i] >= 0; i++) {
            if (i == index || candidate[i] != candidate[i - 1]) {
                element[i] = 1;
                combinationSum(candidate, size, target - candidate[i], i + 1, returnSize, columnSize, element, output);
                element[i] = 0;
            }
        }
    }
}

int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes) {
    int *element = (int *) malloc(candidatesSize * sizeof(int));
    *returnColumnSizes = (int *) malloc(1000 * sizeof(int));
    for (int i = 0; i < candidatesSize; i++) {
        element[i] = 0;
    }
    *returnSize = 0;
    int **output = (int **) malloc(1000 * sizeof(int *));
    for (int i = 0; i < candidatesSize; i++) {
        for (int j = i + 1; j < candidatesSize; j++) {
            if (candidates[j] < candidates[i]) {
                int temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
    combinationSum(candidates, candidatesSize, target, 0, returnSize, *returnColumnSizes, element, output);
    return output;
}
