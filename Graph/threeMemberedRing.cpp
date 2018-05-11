#include <vector>
using namespace std;
#define pb push_back
const int maxn = 2e5+10;
vector<int> G[maxn];
int deg[maxn];
struct edge
{
    int u, v;
}es[maxn];
int vis[maxn];
void init(int n)
{
    memset(deg, 0, sizeof(deg));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++)G[i].clear();
}
int Counting()
{
    int n, m, ans = 0;
    while(scanf("%d%d", &n, &m) != EOF){
        init(n);
        for(int i = 1; i <= m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            es[i].u = u, es[i].v = v;
            deg[u]++, deg[v]++;
        }
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
    }
    return ans;
}
