#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1e5+10;
vector<int> G[maxn];
stack<int> S;
int low[maxn], dfn[maxn], scc[maxn];
int n, cnt, idx;
void dfs(int u, int f)
{
    low[u] = dfn[u] = ++idx;
    S.push(u);
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(!scc[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        cnt++;
        while(1){
            int x = S.top(); S.pop();
            scc[x] = cnt;
            if(x == u)break;
        }
    }
}
void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
}
