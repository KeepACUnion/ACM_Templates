#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mk make_pair
const int maxn = 1e5+10;
int dfn[maxn], low[maxn], bcc[maxn];
stack<pii> sk;
vector<int> G[maxn];
int n, m, idx, cnt;

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    for(auto v : G[u]){
        if(!dfn[v]){
            sk.push(mk(u, v));
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]){
                cnt++;
                while(1){
                    pii p = sk.top(); sk.pop();
                    bcc[p.fi] = bcc[p.se] = cnt;
                    if(p.fi == u && p.se == v)break;
                }
            }
        }
        else if(dfn[v] < dfn[u] && v != f){
            sk.push(mk(u, v));
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
}
