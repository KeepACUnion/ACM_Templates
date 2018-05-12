#include <cstdio>
using namespace std;
typedef long long ll;
const int MaxN = 100000 + 10, MaxE = (5 * 100000) * 2 + MaxN;
int head[MaxN], pre[MaxN], dom[MaxN], to[MaxE], nxt[MaxE], top;
int bcj[MaxN], semi[MaxN], idom[MaxN], best[MaxN], dfn[MaxN], id[MaxN], fa[MaxN], dfs_clock;
int sons[MaxN];
int n, m;
ll ans;
void addedge(int *h,int fr,int tt)
{
    top ++;
    nxt[top] = h[fr];
    to[top] = tt;
    h[fr] = top;
}
void init()
{
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &a, &b);
        addedge(head, a, b);
        addedge(pre, b, a);
    }
}
int push(int v)
{
    if(v == bcj[v]) return v;
    int y = push(bcj[v]);
    if(dfn[semi[best[bcj[v]]]] < dfn[semi[best[v]]]) best[v] = best[bcj[v]];
    return bcj[v] = y;
}//带权并查集路径压缩
void dfs(int rt)
{
    dfn[rt] = ++dfs_clock;
    id[dfs_clock] = rt;
    for(int i = head[rt]; i; i = nxt[i])
        if(!dfn[to[i]])
        {
            dfs(to[i]);
            fa[to[i]] = rt;
        }

}//求出dfs序
void tarjan()
{
    for(int i = dfs_clock, u; i >= 2; --i)
    {//按dfs序从大到小计算
        u = id[i];
        for(int j = pre[u]; j; j = nxt[j])//semi
        {
            if(!dfn[to[j]]) continue;
            push(to[j]);
            if(dfn[semi[best[to[j]]]] < dfn[semi[u]]) semi[u] = semi[best[to[j]]];
        }
        addedge(dom, semi[u], u);
        bcj[u] = fa[u];u = id[i - 1];
        for(int j = dom[u]; j; j = nxt[j])//idom
        {
            push(to[j]);
            if(semi[best[to[j]]] == u) idom[to[j]] = u;
            else idom[to[j]] = best[to[j]];
        }
    }
    for(int i = 2, u; i <= dfs_clock; ++i)
    {
        u = id[i];
        if(idom[u] != semi[u]) idom[u] = idom[idom[u]];
    }
}
void calc_son()
{
    for(int i = dfs_clock, u; i >= 2; --i)
    {
        u = id[i];
        ++ sons[u];
        if(idom[u] != 1) sons[idom[u]] += sons[u];
        else ans -= ((ll)sons[u] * (ll)(sons[u] - 1)) / 2ll;
    }
}
void solve()
{
    for(int i = 1; i <= n; ++i) bcj[i] = semi[i] = best[i] = i;
    dfs_clock = 0;
    dfs(1);
    tarjan();
    ans = ((ll)dfs_clock * (ll)(dfs_clock - 1)) / 2ll;
    calc_son();
    printf("%lld\n", ans);
}
