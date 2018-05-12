#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define mk make_pair
#define fi first 
#define se second
const int maxn = 1e3+10;
const int maxm = 2e4+10;
struct edge
{
    int to, cap, nxt;
}es[maxm];
int head[maxn], iter[maxn], lev[maxn];
int deg[maxn];
vector<int> G[maxn];
stack<int> S;
pii p[maxm];
int n, m, cnt;
void add_edge(int u, int v, int cap)
{
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}
bool solve()
{
    int num = 0;
    for(int i = 0; i < m; i++){
        int u, v, type;
        scanf("%d%d%d", &u, &v, &type);
        deg[u]++, deg[v]--;
        if(type == 1)p[num++] = mk(u, v);//undirected
        else G[u].pb(v);//directed
    }
    bool flg = 1;
    int src = n+1, dst = src+1;
    for(int i = 1; i <= n; i++){
        if(deg[i]%2 != 0){
            flg = 0;
            break;
        }
        if(deg[i] > 0)add_edge(src, i, deg[i]/2);
        else if(deg[i] < 0)add_edge(i, dst, -deg[i]/2);
    }
    if(!flg)return 0;//没有合法欧拉路
    for(int i = 0; i < num; i++)add_edge(p[i].fi, p[i].se, 1);
    max_flow(src, dst);
    for(int i = head[src]; ~i; i = es[i].nxt){
        if(es[i].cap){
            flg = 0;
            break;
        }
    }
    if(!flg)return 0;
    else{
        for(int i = 1; i <= n; i++){
            for(int j = head[i]; ~j; j = es[j].nxt){
                int u = i, v = es[j].to;
                if(v <= n && es[j].cap)G[u].pb(v);
            }
        }
        euler();
    }
    return 1;
}
