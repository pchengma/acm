// LeetCode: 1323. Maximum 69 Number (Easy)
int maximum69Number(int num) {
    int temp = num;
    int countDigit = 0;
    while (temp > 0) {
        temp = temp / 10;
        countDigit++;
    }
    int result[countDigit];
    temp = num;
    int i = countDigit - 1;
    while (temp > 0) {
        result[i] = temp % 10;
        i--;
        temp = temp / 10;
    }
    i = 0;

    while (i < countDigit) {
        if (result[i] == 6) {
            result[i] = 9;
            break;
        }
        i++;
    }
    i = countDigit - 1;
    int j = 0;
    int res = 0;

    while (i >= 0) {
        res = res + (result[i] * pow(10, j));
        j++;
        i--;
    }
    return res;
}