// LeetCode: 2225. Find Players With Zero or One Losses (Medium)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **findWinners(int **matches, int matchesSize, int *matchesColSize, int *returnSize, int **returnColumnSizes) {
    int hashSetNum[100001] = {0};
    int hashSeLoser[100001] = {0};
    for (int i = 0; i < matchesSize; i++) {
        hashSetNum[matches[i][0]] = 1;
        hashSetNum[matches[i][1]] = 1;
        hashSeLoser[matches[i][1]]++;
    }

    int **returnNums = (int **) malloc(sizeof(int *) * 2);
    *returnColumnSizes = (int *) malloc(sizeof(int) * 2);
    *returnSize = 2;
    returnNums[0] = NULL;
    returnNums[1] = NULL;
    (*returnColumnSizes)[0] = 0;
    (*returnColumnSizes)[1] = 0;
    for (int i = 0; i < 100001; i++) {
        if (hashSetNum[i] == 1) {
            if (hashSeLoser[i] == 0 || hashSeLoser[i] == 1) {
                if (hashSeLoser[i] == 0) {
                    if ((*returnColumnSizes)[0] == 0) {
                        returnNums[0] = (int *) malloc(sizeof(int) * matchesSize);
                        returnNums[0][0] = i;
                        (*returnColumnSizes)[0] = (*returnColumnSizes)[0] + 1;
                    } else {
                        returnNums[0][(*returnColumnSizes)[0]] = i;
                        (*returnColumnSizes)[0] = (*returnColumnSizes)[0] + 1;
                    }
                } else {
                    if ((*returnColumnSizes)[1] == 0) {
                        returnNums[1] = (int *) malloc(sizeof(int) * matchesSize);
                        returnNums[1][0] = i;
                        (*returnColumnSizes)[1] = (*returnColumnSizes)[1] + 1;
                    } else {
                        returnNums[1][(*returnColumnSizes)[1]] = i;
                        (*returnColumnSizes)[1] = (*returnColumnSizes)[1] + 1;
                    }
                }
            }
        }
    }
    return returnNums;
}
