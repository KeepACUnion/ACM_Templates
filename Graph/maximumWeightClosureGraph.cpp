#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 5e3+10;
const int maxm = 2e5+10;
const int INF = 0x3f3f3f3f;
struct edge
{
    int to, cap, nxt;
}es[maxm];
int head[maxn];
bool vis[maxn];
int cnt;
void add_edge(int u, int v, int cap)
{
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}
void dfs(int u)
{
    vis[u] = 1;
    for(int i = head[u]; ~i; i = es[i].nxt){
        edge e = es[i];
        if(e.cap && !vis[e.to])dfs(e.to);
    }
}
int solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int src = n+1, dst = src+1;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        int w; scanf("%d", &w);
        if(w > 0)add_edge(src, i, w), sum += w;
        else if(w < 0)add_edge(i, dst, -w);
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v, INF);
    }
    ll ans = sum-max_flow(src, dst);
    dfs(src);
    int num = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i])num++;
    }
    return ans;
}

