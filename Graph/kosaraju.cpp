#include <vector>
using namespace std;
const int maxn = 1e5+10;
vector<int> G[maxn], G2[maxn];
vector<int> S;
int scc[maxn], cnt, n, m;
bool vis[maxn];
void dfs1(int u)
{
    if(vis[u])return;
    else vis[u] = 1;
    for(auto v : G[u])dfs1(v);
    S.push_back(u);
}
void dfs2(int u)
{
    if(scc[u])return;
    scc[u] = cnt;
    for(auto v : G2[u])dfs2(v);
}
void korasaju()
{
    for(int i = 1; i <= n; i++)dfs1(i);
    for(int i = n-1; i >= 0; i--){
        if(!scc[S[i]]){
            cnt++;
            dfs2(S[i]);
        }
    }
}
