#include <vector>
using namespace std;
#define pb push_back
const int maxn = 2e5+10;
struct edge
{
    int u, v;
}es[maxn];
vector<int> G[maxn];
int deg[maxn], vis[maxn];
int n, m;
int Counting()
{
    int ans = 0;
    for(int i = 1; i <= m; i++){
        int u = es[i].u, v = es[i].v;
        if(deg[u] < deg[v] || (deg[u] == deg[v] && u < v))G[u].pb(v);
        else G[v].pb(u);
    }
    for(int i = 1; i <= m; i++){
        int u = es[i].u, v = es[i].v;
        for(auto w : G[u])vis[w] = i;
        for(auto w : G[v])if(vis[w] == i)ans++;
    }
    return ans;
}
