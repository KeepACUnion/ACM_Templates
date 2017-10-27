#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5 + 10;
int n, k;
struct edge
{
    int u, v, w, next;
}es[maxn * 2];
int size[maxn];
int head[maxn];
int maxv[maxn];
bool vis[maxn];
int dis[maxn];
int ans, Max, root, num;

void addedge(int i, int u, int v, int w)
{
    es[i*2+1].u = u, es[i*2+1].v = v, es[i*2+1].w = w, es[i*2+1].next = head[u];
    head[u] = i*2+1;
    es[i*2+2].u = v, es[i*2+2].v = u, es[i*2+2].w = w, es[i*2+2].next = head[v];
    head[v] = i*2+2;
}

void dfs_size(int u, int f)
{
    size[u] = 1;
    maxv[u] = 0;
    for(int i = head[u]; i; i = es[i].next){
        int v = es[i].v;
        if(v != f && !vis[v]){
            dfs_size(v, u);
            size[u] += size[v];
            if(size[v] > maxv[u])maxv[u] = size[v];
        }
    }
}

void dfs_root(int r, int u, int f)
{
    if(size[r] - size[u] > maxv[u])maxv[u] = size[r] - size[u];
    if(maxv[u] < Max)Max = maxv[u], root = u;
    for(int i = head[u]; i; i = es[i].next){
        int v = es[i].v;
        if(v != f && !vis[v]){
            dfs_root(r, v, u);
        }
    }
}

void dfs_dis(int u, int d, int f)
{
    dis[num++] = d;
    for(int i = head[u]; i; i = es[i].next){
        int v = es[i].v;
        if(v != f && !vis[v]){
            dfs_dis(v, d + es[i].w, u);
        }
    }
}

int calc(int u, int d)
{
    int res = 0;
    num = 0;
    dfs_dis(u, d, 0);
    sort(dis, dis + num);
    int i = 0, j = num - 1;
    while(i < j){
        while(dis[i] + dis[j] > k && i < j)j--;
        res += j - i;
        i++;
    }
    return res;
}

void dfs(int u)
{
    Max = n;
    dfs_size(u, 0);
    dfs_root(u, u, 0);
    ans += calc(root, 0);
    //printf("ans=%d\n", ans);
    vis[root] = 1;
    for(int i = head[root]; i; i = es[i].next){
        int v = es[i].v;
        if(!vis[v]){
            ans -= calc(v, es[i].w);
            //printf("ans=%d\n", ans);
            dfs(v);
        }
    }
}

void work()
{
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    ans = 0;
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(i, u, v, w);
    }
    dfs(1);
    printf("%d\n", ans);
}

int main()
{
    while(scanf("%d%d", &n, &k) != EOF && n){
        work();
    }
    return 0;
}


