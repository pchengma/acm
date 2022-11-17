// LeetCode: 223. Rectangle Area (Medium)
#define max(a, b) (((a) >= (b)) ? (a) : (b))
#define min(a, b) (((a) >= (b)) ? (b) : (a))

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int tmp1, tmp2, tmp3, tmp4;
    long rec1Area, rec2Area, res = 0;

    rec1Area = (long) (ax2 - ax1) * (ay2 - ay1);
    if (rec1Area > INT_MAX) {
        return -1;
    }
    rec2Area = (long) (bx2 - bx1) * (by2 - by1);
    if (rec2Area > INT_MAX) {
        return -1;
    }
    res = rec1Area + rec2Area;
    if (((ax1 <= bx2) && (bx1 <= ax2)) && ((ay2 >= by1) && (by2 >= ay1))) {
        tmp1 = max(ax1, bx1);
        tmp2 = min(ax2, bx2);
        tmp3 = min(ay2, by2);
        tmp4 = max(ay1, by1);
        res = res - (tmp2 - tmp1) * (tmp3 - tmp4);
        if (res > INT_MAX) {
            return -1;
        }
        return (int) res;
    }
    if (res > INT_MAX) {
        return -1;
    }
    return (int) res;
}
