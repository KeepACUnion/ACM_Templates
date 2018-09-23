#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define pb push_back
#define mk make_pair
const int maxn = 1e5+10;
int sz[maxn], mx[maxn];
bool vis[maxn];
vector<pii> G[maxn];
vector<int> dis;
int n, k;
int ans, ms, rt;

void init()
{
    for(int i = 1; i <= n; i++)vis[i] = 0, G[i].clear();
    ans = 0;
}

void dfs_size(int u, int f)
{
    sz[u] = 1;
    mx[u] = 0;
    for(auto p : G[u]){
        if(p.fi != f && !vis[p.fi]){
            dfs_size(p.fi, u);
            sz[u] += sz[p.fi];
            if(sz[p.fi] > mx[u])mx[u] = sz[p.fi];
        }
    }
}

void dfs_root(int r, int u, int f)
{
    if(sz[r]-sz[u] > mx[u])mx[u] = sz[r]-sz[u];
    if(mx[u] < ms)ms = mx[u], rt = u;
    for(auto p : G[u]){
        if(p.fi != f && !vis[p.fi])dfs_root(r, p.fi, u);
    }
}

void dfs_dis(int u, int d, int f)
{
    dis.pb(d);
    for(auto p : G[u]){
        if(p.fi != f && !vis[p.fi])dfs_dis(p.fi, d+p.se, u);
    }
}

int calc(int u, int d)
{
    int res = 0;
    dis.clear();
    dfs_dis(u, d, 0);
    sort(dis.begin(), dis.end());
    int i = 0, j = (int)dis.size()-1;
    while(i < j){
        while(dis[i]+dis[j]> k && i < j)j--;
        res += j-i;
        i++;
    }
    return res;
}

void dfs(int u)
{
    ms = n;
    dfs_size(u, 0);
    dfs_root(u, u, 0);
    ans += calc(rt, 0);
    vis[rt] = 1;
    int pnt = rt;
    for(auto p : G[pnt]){
        if(!vis[p.fi]){
            ans -= calc(p.fi, p.se);
            dfs(p.fi);
        }
    }
}

void pointDivideAndConquer()
{
    dfs(1);
    printf("%d\n", ans);
}
