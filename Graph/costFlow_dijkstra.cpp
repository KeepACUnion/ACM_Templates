#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define pb push_back
#define mk make_pair
const int INF = 0x3f3f3f3f;
const int maxn = 110;
const int maxv = 10100;
int n, m, ans;
struct es
{
    int to, cap, rev, cost;
    es(int to, int cap, int rev, int cost):to(to),cap(cap),rev(rev),cost(cost){}
};
vector<es> G[maxv];
bool vis[maxv];
int dist[maxv];
void add_edge(int from, int to, int cap, int cost)
{
    G[from].pb(es(to, cap, (int)G[to].size(), cost));
    G[to].pb(es(from, 0, (int)G[from].size()-1, -cost));
}
bool dijkstra(int s, int t)
{
    memset(dist, INF, sizeof(dist));
    dist[t] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mk(0, t));
    while(!pq.empty()){
        pii u = pq.top(); pq.pop();
        if(dist[u.se] < u.fi)continue;
        for(int i = 0; i < (int)G[u.se].size(); i++){
            es &e = G[u.se][i];
            if(G[e.to][e.rev].cap && dist[e.to] > dist[u.se]-e.cost){
                dist[e.to] = dist[u.se]-e.cost;
                pq.push(mk(dist[e.to], e.to));
            }
        }
    }
    return dist[s] < INF;
}
int dfs(int v, int t, int f)
{
    vis[v] = 1;
    if(v == t)return f;
    int ret = 0;
    for(int i = 0; i < (int)G[v].size(); i++){
        es &e = G[v][i];
        if(!vis[e.to] && e.cap && dist[v] - e.cost == dist[e.to]){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d){
                ans += e.cost*d;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                ret += d;
                if(ret == f)break;
            }
        }
    }
    return ret;
}
int costflow(int s, int t)
{
    int flow = 0;
    while(dijkstra(s, t)){
        vis[t] = 1;
        while(vis[t]){
            memset(vis, 0, sizeof(vis));
            flow += dfs(s, t, INF);
        }
    }
    return flow;
}
