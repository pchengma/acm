#include<iostream>
using namespace std;

const int N=1001;
int father[N];

int total;

int findSet(int x)
{
    int r=x;
    while(r!=father[r])
        r=father[r];
    return r;
}

void join(int a,int b)
{
    int fa=findSet(a);
    int fb=findSet(b);
    if(fa==fb) return;
    else
    {
        father[fa]=fb;
        total--;//统一了2个阵营的boss（根节点),所以需要数目-1
    }
}
