// LeetCode: 1926. Nearest Exit from Entrance in Maze (Medium)
typedef struct {
    int front;
    int rear;
    int **coords;
    int dist;
} queue;

queue *createQueue(int size) {
    queue *ret = malloc(sizeof(queue));
    ret->front = -1;
    ret->rear = -1;
    ret->coords = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        ret->coords[i] = malloc(3 * sizeof(int));
    }
    return ret;
}

void enqueue(queue *node, int x, int y, int dist) {
    if (node->front == -1) {
        node->front = 0;
        node->rear = 0;
    } else {
        node->rear++;
    }
    node->coords[node->rear][0] = x;
    node->coords[node->rear][1] = y;
    node->coords[node->rear][2] = dist;
}

void dequeue(queue *node) {
    node->front++;
    if (node->rear < node->front) {
        node->rear = -1;
        node->front = -1;
    }
}

bool queueIsEmpty(queue *node) {
    return node->front == -1 ? true : false;
}

bool isExit(queue *node, int startx, int starty, int rows, int cols) {
    int x = node->coords[node->front][0], y = node->coords[node->front][1];
    if ((x == 0 || x == rows - 1) && (x != startx || y != starty)) {
        return true;
    } else if ((y == 0 || y == cols - 1) && (x != startx || y != starty)) {
        return true;
    }
    return false;
}

int helper(char **maze, int **visited, int rows, int cols, int *entrance) {
    int x = entrance[0], y = entrance[1], startx = x, starty = y;
    visited[x][y] = 1;
    queue *bfs = createQueue(10000);
    enqueue(bfs, x, y, 0);
    while (!queueIsEmpty(bfs)) {
        int currx = bfs->coords[bfs->front][0];
        int curry = bfs->coords[bfs->front][1];
        int currdist = bfs->coords[bfs->front][2];
        if (isExit(bfs, startx, starty, rows, cols))
            return currdist;
        dequeue(bfs);
        if (currx < rows - 1 && maze[currx + 1][curry] != '+' && !visited[currx + 1][curry]) {
            enqueue(bfs, currx + 1, curry, currdist + 1);
            visited[currx + 1][curry] = 1;
        }
        if (currx > 0 && maze[currx - 1][curry] != '+' && !visited[currx - 1][curry]) {
            enqueue(bfs, currx - 1, curry, currdist + 1);
            visited[currx - 1][curry] = 1;
        }
        if (curry < cols - 1 && maze[currx][curry + 1] != '+' && !visited[currx][curry + 1]) {
            enqueue(bfs, currx, curry + 1, currdist + 1);
            visited[currx][curry + 1] = 1;
        }
        if (curry > 0 && maze[currx][curry - 1] != '+' && !visited[currx][curry - 1]) {
            enqueue(bfs, currx, curry - 1, currdist + 1);
            visited[currx][curry - 1] = 1;
        }
    }
    return -1;
}

int nearestExit(char **maze, int mazeSize, int *mazeColSize, int *entrance, int entranceSize) {
    int **visited = malloc(mazeSize * sizeof(int *));
    for (int i = 0; i < mazeSize; i++) {
        visited[i] = malloc(*mazeColSize * sizeof(int));
        memset(visited[i], 0, *mazeColSize * sizeof(int));
    }
    return helper(maze, visited, mazeSize, *mazeColSize, entrance);
}
