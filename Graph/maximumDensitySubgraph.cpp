#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const double eps = 1e-10;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+10;
const int maxm = 1e4+10;
struct edge
{
    int to, nxt;
    long double cap;
}es[maxm];
int head[maxn], iter[maxn], lev[maxn];
pii p[maxm];
bool vis[maxn];
int N, M, cnt;
void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, long double cap)
{
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}
bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = es[i].nxt){
            edge &e = es[i];
            if(e.cap > eps && lev[e.to] < 0){
                lev[e.to] = lev[u]+1;
                if(e.to == t)return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}
long double dfs(int v, int t, long double f)
{
    if(v == t)return f;
    long double ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(e.cap > eps && lev[e.to] == lev[v]+1){
            long double d = dfs(e.to, t, min(e.cap, f-ret));
            if(d > eps){
                e.cap -= d;
                es[i^1].cap += d;
                ret += d;
                if(ret+eps >= f)break;
            }
        }
    }
    if(ret < eps)lev[v] = 0;
    return ret;
}
long double max_flow(int s, int t)
{
    long double ret = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        ret += dfs(s, t, INF);
    }
    return ret;
}
bool maximumDensitySubgraph(long double m)
{
    init();
    int src = N+M+1, dst = src+1;
    long double sum = 0;
    for(int i = 1; i <= N; i++)add_edge(i, dst, m);
    for(int i = 1; i <= M; i++){
        add_edge(src, i+N, 1), sum += 1;
        add_edge(i+N, p[i].fi, INF);
        add_edge(i+N, p[i].se, INF);
    }
    long double ret = sum-max_flow(src, dst);
    return ret > eps;
}
void dfs(int u)
{
    vis[u] = 1;
    for(int i = head[u]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(!vis[e.to] && e.cap > eps)dfs(e.to);
    }
}
void solve()
{
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        p[i] = mk(u, v);
    }
    long double l = 0, r = M, ans = 0;
    while(l+1.0/(N*N) <= r){
        long double m = (l+r)/2;
        if(maximumDensitySubgraph(m)){
            ans = m;
            l = m;
        }
        else r = m;
    }
    maximumDensitySubgraph(ans);
    int src = N+M+1;
    dfs(src);
    vector<int> vec;
    for(int i = 1; i <= N; i++)if(vis[i])vec.pb(i);
    if(vec.empty())vec.pb(1);
    printf("%d\n", (int)vec.size());
    for(int i = 0; i < (int)vec.size(); i++)printf("%d\n", vec[i]);
}
