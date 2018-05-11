#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
struct edge
{
    int u, v, w;
    bool operator < (const edge &rhs)const
    {
        return w < rhs.w;
    }
}es[maxn];
int par[maxn];
int n, m;
void init()
{
    for(int i = 0; i <= n; i++)par[i] = i;
}
int find(int x)
{
    return par[x]==x?x:par[x]=find(par[x]);
}
bool unite(int x, int y)
{
    x = find(x), y = find(y);
    if(x != y){
        par[x] = y;
        return 1;
    }
    return 0;
}
int kruskal()
{
    sort(es, es+m);
    int ret = 0;
    for(int i = 0; i < m; i++){
        if(unite(es[i].u, es[i].v))ret += es[i].w;
    }
    return ret;
}
