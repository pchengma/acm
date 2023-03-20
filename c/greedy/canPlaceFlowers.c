// LeetCode: 605. Can Place Flowers (Easy)
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    int prev = -1;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 1) {
            if (prev < 0) {
                count += i / 2;
            } else {
                count += (i - prev - 2) / 2;
            }
            if (count >= n) {
                return true;
            }
            prev = i;
        }
    }
    if (prev < 0) {
        count += (flowerbedSize + 1) / 2;
    } else {
        count += (flowerbedSize - prev - 1) / 2;
    }
    return count >= n;
}

