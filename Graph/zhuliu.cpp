//O(nm)
#include <cstring>
const int INF = 0x3f3f3f3f;
const int maxn = 1010;
const int maxe = 40100;
struct edge
{
    int u, v, w;
}es[maxe];
int vis[maxn], id[maxn], pre[maxn], in[maxn];
int n, m;
//如果是无根的最小树形图，那么建一个超级根向所有点连边，权值为sum(w)+1，如果ret-sum>=sum，无解，否则有解
int zhuliu(int root)
{
    int ret = 0;
    while(1){
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        memset(in, 0x3f, sizeof(in));
        for(int i = 0; i < m; i++)if(es[i].u != es[i].v && in[es[i].v] > es[i].w){
            in[es[i].v] = es[i].w;
            pre[es[i].v] = es[i].u;
        }
        for(int i = 0; i < n; i++)if(i != root && in[i] == INF)return INF;//不联通
        in[root] = 0;
        int loop = 0;
        for(int i = 0; i < n; i++){
            ret += in[i];
            int v = i;
            while(v != root && id[v] == -1 && vis[v] != i){
                vis[v] = i;
                v = pre[v];
            }
            if(vis[v] == i){
                for(int j = pre[v]; j != v; j = pre[j])id[j] = loop;
                id[v] = loop++;
            }
        }
        if(!loop)break;
        for(int i = 0; i < n; i++)if(id[i] == -1)id[i] = loop++;
        for(int i = 0; i < m; i++){
            int v = es[i].v;
            es[i].u = id[es[i].u];
            es[i].v = id[es[i].v];
            if(es[i].u != es[i].v)es[i].w -= in[v];
        }
        root = id[root];
        n = loop;
    }
    return ret;
}
