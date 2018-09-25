#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1e5+10;
const int maxd = 20;
vector<int> G[maxn];
int beg[maxn], id[maxn*2], dep[maxn*2], LOG[maxn*2];
int st[maxn][maxd];
int n, tot;
void init_rmq()
{
    for(int i = 0; i < tot; i++)st[i][0] = i;
    for(int i = 0, j = 0; i < tot; i++){
        while(i >= (1<<(j+1))) j++;
        LOG[i] = j;
    }
    for(int j = 1; (1<<j) <= tot; j++){
        for(int i = 0; i+(1<<j)-1 < tot; i++){
            int u = st[i][j-1], v = st[i+(1<<(j-1))][j-1];
            st[i][j] = dep[u]<dep[v]?u:v;
        }
    }
}
int query(int l, int r)
{
    int k = LOG[r-l+1];
    int u = st[l][k], v = st[r-(1<<k)+1][k];
    return dep[u]<dep[v]?u:v;
}
int lca(int x, int y)
{
    int l = beg[x], r = beg[y];
    if(l > r)swap(l, r);
    return id[query(l, r)];
}
void dfs(int u, int f, int d)
{
    beg[u] = tot; id[tot] = u; dep[tot] = d; tot++;
    for(auto v : G[u]){
        if(v == f)continue;
        dfs(v, u, d+1);
        id[tot] = u; dep[tot] = d; tot++;
    }
}
