#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;
struct edge
{
    int to, cap, nxt;
    edge(){}
    edge(int to, int cap, int nxt):to(to), cap(cap), nxt(nxt){}
}es[maxn*2];
int head[maxn];
int lev[maxn], iter[maxn];
int n, m, cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w)
{
    es[cnt] = edge(v, w, head[u]);
    head[u] = cnt++;
    es[cnt] = edge(u, w, head[v]);
    head[v] = cnt++;
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int i = head[v]; ~i; i = es[i].nxt){
            edge &e = es[i];
            if(e.cap > 0 && lev[e.to] < 0){
                lev[e.to] = lev[v]+1;
                if(e.to == t)return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

int dfs(int v, int t, int f)
{
    if(v == t)return f;
    int ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(e.cap > 0 && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d > 0){
                e.cap -= d;
                es[i^1].cap += d;
                ret += d;
                if(ret == f)break;
            }
            
        }
    }
    if(!ret)lev[v] = 0;
    return ret;
}

int max_flow(int s, int t)
{
    int flow = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        flow += dfs(s, t, INF);
    }
    return flow;
}
