#include <algorithm>
using namespace std;
const int maxn = 1e6+10;
const int maxd = 21;
int anc[maxn][maxd];//anc[i][0]->par[i]
int dep[maxn];
int n;
void init_lca()
{
    for(int i = 1; i < maxd; i++){
        for(int j = 1; j <= n; j++){
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
}
int lca(int u, int v)
{
    if(dep[u] < dep[v])swap(u, v);
    for(int i = maxd-1; i >= 0; i--){
        if(dep[anc[u][i]] >= dep[v])u = anc[u][i];
    }
    if(u == v)return u;
    for(int i = maxd-1; i >= 0; i--){
        if(anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}
