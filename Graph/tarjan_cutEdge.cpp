#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define mk make_pair
const int maxn = 1e5+10;
int dfn[maxn], low[maxn];
vector<int> G[maxn];
vector<pii> cut;
int n, idx;
void dfs(int u, int f)
{
    dfn[u] = low[u] = idx++;
    for(auto v : G[u]){
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
                cut.pb(mk(min(u, v), max(u, v)));
            }
        }
        else if(dfn[v] < dfn[u])low[u] = min(low[u], dfn[v]);
    }   
}
void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
}
