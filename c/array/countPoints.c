// LeetCode: 2103. Rings and Rods (Easy)
const int POLE_NUM = 10;
const int COLOR_NUM = 3;

static int getColorId(char color) {
    if (color == 'R') {
        return 0;
    } else if (color == 'G') {
        return 1;
    }
    return 2;
}

int countPoints(char *rings) {
    int state[POLE_NUM][COLOR_NUM];
    int n = strlen(rings);
    memset(state, 0, sizeof(state));
    for (int i = 0; i < n; i += 2) {
        char color = rings[i];
        int pole_index = rings[i + 1] - '0';
        state[pole_index][getColorId(color)] = 1;
    }
    int res = 0;
    for (int i = 0; i < POLE_NUM; i++) {
        bool flag = true;
        for (int j = 0; j < COLOR_NUM; j++) {
            if (state[i][j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res++;
        }
    }
    return res;
}
