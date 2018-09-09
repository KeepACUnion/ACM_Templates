#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define pb push_back
const int maxn = 1e5+10;
const int maxm = 1e6+10;
struct edge
{
    int to, nxt;
    edge(){}
    edge(int to, int nxt):to(to), nxt(nxt){}
}es[maxm];
int head[maxn], deg[maxn];
bool used[maxm], vis[maxn];
vector<int> seq;
int n, m, cnt;

void init()
{
    memset(deg, 0, sizeof(deg));
    memset(vis, 0, sizeof(vis));
    memset(used, 0, sizeof(used));

}

void add_edge(int u, int v)
{
    es[cnt] = edge(v, head[u]);
    head[u] = cnt++;
    es[cnt] = edge(u, head[v]);
    head[v] = cnt++;
}

void dfs(int u)
{
    vis[u] = 1;
    for(int i = head[u]; ~i; i = head[u]){
        head[u] = es[i].nxt;
        if(used[i>>1])continue;
        used[i>>1] = 1;
        int v = es[i].to;
        dfs(v);
        seq.pb(i);
    }
}
