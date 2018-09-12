#include <cstring>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
#define mk make_pair
#define pb push_back
#define SZ(x) ((int)x.size())
#define fi first
#define se second
const double eps = 1e-10;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+10;
const int maxm = 1e4+10;
struct edge
{
    int to, rev;
    long double cap;
    edge(){}
    edge(int to, int rev, long double cap):to(to), rev(rev), cap(cap){}
};
vector<edge> G[maxn];
int lev[maxn];
pii in[maxm];
bool vis[maxn];
int n, m, cnt;
void init()
{
    for(int i = 0; i < maxn; i++)G[i].clear();
}
void add_edge(int u, int v, long double cap)
{
    G[u].pb(edge(v, SZ(G[v]), cap));
    G[v].pb(edge(u, SZ(G[u])-1, 0));
}
bool solve(long double mid)
{
    init();
    int src = n+m+1, dst = src+1;
    long double sum = 0;
    for(int i = 1; i <= n; i++)add_edge(i, dst, mid);
    for(int i = 1; i <= m; i++){
        add_edge(src, i+n, 1), sum += 1;
        add_edge(i+n, in[i].fi, INF);
        add_edge(i+n, in[i].se, INF);
    }
    long double ret = sum-max_flow(src, dst);
    return ret > eps;
}
void dfs(int u)
{
    vis[u] = 1;
    for(auto e : G[u]){
        if(!vis[e.to] && e.cap > eps)dfs(e.to);
    }
}
vector<int> maximumDensitySubgraph()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        in[i] = mk(u, v);
    }
    long double l = 0, r = m, ans = 0;
    while(l+1.0/(n*n) <= r){
        long double mid = (l+r)/2;
        if(solve(mid)){
            ans = mid;
            l = mid;
        }
        else r = mid;
    }
    solve(ans);
    int src = n+m+1;
    dfs(src);
    vector<int> vec;
    for(int i = 1; i <= n; i++)if(vis[i])vec.pb(i);
    if(vec.empty())vec.pb(1);
    return vec;
}
