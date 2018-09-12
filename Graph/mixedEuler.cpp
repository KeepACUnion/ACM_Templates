#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define mk make_pair
#define SZ(x) ((int)x.size())
#define fi first 
#define se second
const int maxn = 1e3+10;
const int maxm = 2e4+10;
struct edge
{
    int to, cap, rev;
    edge(){}
    edge(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
};
vector<edge> G[maxn];
vector<int> G2[maxn];
int lev[maxn], deg[maxn];
stack<int> S;
pii p[maxm];
int n, m;
void add_edge(int u, int v, int cap)
{
    G[u].pb(edge(v, cap, SZ(G[v])));
    G[v].pb(edge(u, 0, SZ(G[u])-1));
}
bool mixedEuler()
{
    int num = 0;
    for(int i = 0; i < m; i++){
        int u, v, type;
        scanf("%d%d%d", &u, &v, &type);
        deg[u]++, deg[v]--;
        if(type == 1)p[num++] = mk(u, v);//undirected
        else G2[u].pb(v);//directed
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
    for(auto e : G[src]){
        if(e.cap){
            flg = 0;
            break;
        }
    }
    if(!flg)return 0;
    else{
        for(int i = 1; i <= n; i++){
            for(auto e : G[i]){
                if(e.to <= n && e.cap)G2[i].pb(e.to);
            }
        }
        euler();
    }
    return 1;
}
