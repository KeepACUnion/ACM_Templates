#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
vector<int> G[maxn];
int dfn[maxn], low[maxn], cut[maxn];
int n, idx;
void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    int cnt = 0;
    for(auto v : G[u]){
        if(v == f)continue;
        if(!dfn[v]){
            cnt++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u])cut[u] = 1;
        }
        if(dfn[v] < dfn[u])low[u] = min(low[u], dfn[v]);
    }
    if(!f && cnt <= 1)cut[u] = 0;
}
int tarjan()
{
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
    for(int i = 1; i <= n; i++){
        if(cut[i])ret++;
    }
    return ret;
}
