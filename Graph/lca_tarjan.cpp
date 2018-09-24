#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
struct data
{
    int v, rev, f;
    data(){}
    data(int v, int rev):v(v), rev(rev){}
};
vector<data> q[maxn];
vector<int> G[maxn];
int par[maxn];
bool vis[maxn];
int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}
void unite(int u, int v)
{
    u = find(u); v = find(v);
    if(u != v)par[u] = v;
}
void dfs(int u)
{
    vis[u] = 1;
    for(auto v : G[u]){ 
        if(!vis[v]){    
            dfs(v);
            unite(v, u);
        }
    }
    for(auto &d : q[u]){
        if(vis[d.v])d.f = q[d.v][d.rev].f = find(d.v);
    }
}
