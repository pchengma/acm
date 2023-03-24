// LeetCode: 1466. Reorder Routes to Make All Paths Lead to the City Zero (Medium)
typedef struct AdjNode {
    int d;
    int w;
    struct AdjNode* next;
} Adj;

typedef struct { 
    Adj* adjs;
    bool visited;
} City;

typedef struct {
    City** citys;
    int n;
} CitysWay;

void CitysWayAddEage(CitysWay* obj, int s, int d, int w)
{
    Adj* adj = malloc(sizeof(Adj));
    adj->d = d;
    adj->w = w;
    adj->next = obj->citys[s]->adjs;
    obj->citys[s]->adjs = adj;
    return;
}

void CitysWayInitConnections(CitysWay* obj, int** connections, int connectionsSize, int* connectionsColSize)
{
    for (int i = 0; i < connectionsSize; i++) {
        CitysWayAddEage(obj, connections[i][0], connections[i][1], 0);
        CitysWayAddEage(obj, connections[i][1], connections[i][0], 1);
    }
    return;
}

CitysWay* CitysWayCreate(int n, int** connections, int connectionsSize, int* connectionsColSize)
{
    CitysWay* obj = malloc(sizeof(CitysWay));
    obj->n = n;
    obj->citys = malloc(sizeof(City*) * n);
    for (int i = 0; i < n; i++) {
        obj->citys[i] = malloc(sizeof(City));
        obj->citys[i]->adjs = NULL;
        obj->citys[i]->visited = false;
    }

    CitysWayInitConnections(obj, connections, connectionsSize, connectionsColSize);
    return obj;
}

int CitysWayMinReorder(CitysWay* obj, int s)
{
    obj->citys[s]->visited = true;
    Adj* curAdj = obj->citys[s]->adjs;
    int count = 0;
    while (curAdj != NULL) {
        if (obj->citys[curAdj->d]->visited) {
            curAdj = curAdj->next;
            continue;
        }

        if (curAdj->w == 0) {
            count++;
        }
        count += CitysWayMinReorder(obj, curAdj->d);
        curAdj = curAdj->next;
    }
    return count;
}

void CitysWayFree(CitysWay* obj)
{
    for (int i = 0; i < obj->n; i++) {
        Adj* curAdj = obj->citys[i]->adjs;
        Adj* del = NULL;
        while (curAdj != NULL) {
            del = curAdj;
            curAdj = curAdj->next;
            free(del);
        }
        free(obj->citys[i]);
    }
    free(obj->citys);
    free(obj);
    return;
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize)
{
    CitysWay* obj = CitysWayCreate(n, connections, connectionsSize, connectionsColSize);
    int minReorderCount = CitysWayMinReorder(obj, 0);
    CitysWayFree(obj);
    return minReorderCount;
}

