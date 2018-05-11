#include <vector>
using namespace std;
const int maxn = 1e5+10;
vector<int> G[maxn], G2[maxn];
vector<int> S;
int sccno[maxn], scc_cnt, n, m;
bool vis[maxn];
void dfs1(int u)
{
    if(vis[u])return;
    vis[u] = 1;
    for(int i = 0; i < (int)G[u].size(); i++)dfs1(G[u][i]);
    S.push_back(u);
}
void dfs2(int u)
{
    if(sccno[u])return;
    sccno[u] = scc_cnt;
    for(int i = 0; i < (int)G2[u].size(); i++)dfs2(G2[u][i]);
}
void Korasaju()
{
    scc_cnt = 0;
    S.clear();
    memset(sccno, 0, sizeof(sccno));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)dfs1(i);
    for(int i = n-1; i >= 0; i--){
        if(!sccno[S[i]]){
            ++scc_cnt;
            dfs2(S[i]);
        }
    }
}
