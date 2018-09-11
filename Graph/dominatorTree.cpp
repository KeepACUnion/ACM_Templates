#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
#define pb push_back
const int maxn = 1e6+10;
vector<int> G[maxn], G2[maxn], dom[maxn];
int dfn[maxn], id[maxn], fa[maxn];
int semi[maxn], best[maxn], par[maxn], idom[maxn];
ll ans[maxn];
int n, m, idx;
void init()
{
    for(int i = 0; i <= n; i++)G[i].clear(), G2[i].clear(), dom[i].clear();
    memset(dfn, 0, sizeof(dfn));
    memset(ans, 0, sizeof(ans));
    idx = 0;
}
void dfs(int u)
{
    dfn[u] = ++idx;
    id[idx] = u;
    for(auto v : G[u]){
        if(!dfn[v]){
            dfs(v);
            fa[v] = u;
        }
    }
}
int find(int x)
{
    if(par[x] == x)return x;
    int y = find(par[x]);
    if(dfn[semi[best[par[x]]]] < dfn[semi[best[x]]])best[x] = best[par[x]];
    return par[x] = y;
}
void tarjan()
{
    for(int i = idx; i >= 2; i--){
        int u = id[i];
        for(auto v : G2[u]){
            if(!dfn[v])continue;
            find(v);
            if(dfn[semi[best[v]]] < dfn[semi[u]])semi[u] = semi[best[v]];
        }
        dom[semi[u]].pb(u);
        int x = par[u] = fa[u];
        for(auto v : dom[x]){
            find(v);
            if(dfn[semi[best[v]]] < dfn[fa[u]])idom[v] = best[v];
            else idom[v] = fa[u];
        }
        dom[x].clear();
    }
    for(int i = 2; i <= idx; i++){
        int u = id[i];
        if(idom[u] != semi[u])idom[u] = idom[idom[u]];
        dom[idom[u]].pb(u);
    }
}
void solve(int s)
{
    for(int i = 1; i <= n; i++)par[i] = best[i] = semi[i] = i; 
    dfs(s);
    tarjan();
}
