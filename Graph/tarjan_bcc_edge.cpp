#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5+10;
const int maxm = 1e6+10;
struct edge
{
    int to, nxt;
}es[maxm];
int dfn[maxn], low[maxn], bcc[maxn], head[maxn];
bool cut[maxm];
int n, m, idx, cnt;
void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    for(int i = head[u]; ~i; i = es[i].nxt){
        int v = es[i].to;
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u])cut[i>>1] = 1;
        }
        else if(dfn[v] < dfn[u])low[u] = min(low[u], dfn[v]);
    }
}

void dfs2(int u)
{
    bcc[u] = cnt;
    for(int i = head[u]; ~i; i = es[i].nxt){
        if(!cut[i>>1])dfs2(es[i].to);
    }
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
    for(int i = 1; i <= n; i++){
        if(!bcc[i]){
            cnt++;
            dfs2(i);
        }       
    }
}
