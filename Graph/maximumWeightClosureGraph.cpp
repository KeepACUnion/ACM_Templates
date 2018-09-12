#include <cstdio>
#include <vector>
using namespace std;
#define pb push_back
#define SZ(x) ((int)x.size())
typedef long long ll;
const int maxn = 5e3+10;
const int INF = 0x3f3f3f3f;
struct edge
{
    int to, cap, rev;
    edge(){}
    edge(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
};
vector<edge> G[maxn];
bool vis[maxn];
int cnt;
void add_edge(int u, int v, int cap)
{
    G[u].pb(edge(v, cap, SZ(G[v])));
    G[v].pb(edge(u, cap, SZ(G[u])-1));
}
void dfs(int u)
{
    vis[u] = 1;
    for(auto e : G[u]){
        if(e.cap && !vis[e.to])dfs(e.to);
    }
}
ll maximumWeightClosureGraph()
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
    vector<int> vec;
    for(int i = 1; i <= n; i++){
        if(vis[i])vec.pb(i);//所选点集
    }
    return ans;
}

