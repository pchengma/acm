// LeetCode: 2360. Longest Cycle in a Graph (Hard)
#define INVALID_VALUE -1
#define MAX_VALUE(x, y) (((x) > (y)) ? (x) : (y))

int longestCycle(int *edges, int edgesSize) {
    int x = 0, counter = 0, zerosSize = 0, result = INVALID_VALUE;
    int degree[edgesSize], zeros[edgesSize];
    bool mark[edgesSize];

    memset(degree, 0, sizeof(degree));
    memset(mark, 0, sizeof(mark));

    while (edgesSize > x) {
        if (INVALID_VALUE != edges[x]) {
            degree[edges[x]]++;
        }
        x++;
    }

    x = 0;
    while (edgesSize > x) {
        if (0 == degree[x]) {
            zeros[zerosSize] = x;
            zerosSize++;
        }
        x++;
    }

    x = 0;
    while (zerosSize > x) {
        mark[zeros[x]] = true;
        if (INVALID_VALUE != edges[zeros[x]]) {
            degree[edges[zeros[x]]]--;
            if (0 == degree[edges[zeros[x]]]) {
                zeros[zerosSize] = edges[zeros[x]];
                zerosSize++;
            }
        }
        x++;
    }

    if (edgesSize == x) {
        return result;
    }

    x = 0;
    while (edgesSize > x) {
        counter = 0;
        while (false == mark[x]) {
            counter++;
            mark[x] = true;
            x = edges[x];
        }
        result = MAX_VALUE(result, counter);
        x++;
    }

    return result;
}
