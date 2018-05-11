#include <vector>
using namespace std;
typedef long long ll;
#define pb push_back
const int maxn = 110;
const int maxe = 1010;
struct edge
{
    int u, v, w;
    bool operator < (const edge &rbs)const
    {
        return w<rbs.w;
    }
}es[maxe];
ll mat[maxn][maxn];
int link[maxn][maxn];
int fa[maxn];
int par[maxn];
bool vis[maxn];
vector<int> vec[maxn];
int n, m;
ll mod;
void init()
{
    memset(link, 0, sizeof(link));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++)fa[i] = i, par[i] = i;
}
int find(int x, int arr[])
{
    return x==arr[x]?x:arr[x]=find(arr[x], arr);
}
ll det(int sz)
{
    ll ret = 1;
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++)mat[i][j] = (mat[i][j]%mod+mod)%mod;
    }
    for(int i = 1; i < sz; i++){
        for(int j = i+1; j < sz; j++){
            while(mat[j][i]){
                ll t = mat[i][i]/mat[j][i];
                for(int k = i; k < sz; k++){
                    mat[i][k] = (mat[i][k]-mat[j][k]*t)%mod;
                    swap(mat[i][k], mat[j][k]);
                }
                ret = (-ret+mod)%mod;
            }
        }
        if(!mat[i][i])return 0;
        ret = ret*mat[i][i]%mod;
    }
    return (ret+mod)%mod;
}
ll solve()
{
    sort(es, es+m);
    ll ret = 1;
    int pre = -1;
    for(int i = 0; i <= m; i++){
        if(es[i].w != pre || i == m){
            for(int j = 0; j < n; j++){
                if(vis[j]){
                    int fj = find(j, par);
                    vec[fj].pb(j);
                    fa[j] = fj;
                    vis[j] = 0;
                }
            }
            for(int j = 0; j < n; j++){
                int sz = vec[j].size();
                if(sz <= 1)continue;
                memset(mat, 0, sizeof(mat));
                for(int k = 0; k < sz; k++){
                    for(int h = k+1; h < sz; h++){
                        int u = vec[j][k], v = vec[j][h];
                        mat[k][h] = mat[h][k] = -link[u][v];
                        mat[k][k] += link[u][v];
                        mat[h][h] += link[v][u];
                    }
                }
                ret = ret*det(sz)%mod;
            }
            for(int j = 0; j < n; j++){
                vec[j].clear();
            }
            if(i == m)break;
        }
        int u = es[i].u, v = es[i].v;
        u = find(u, fa); v = find(v, fa);
        if(u == v)continue;
        vis[u] = vis[v] = 1;
        par[find(v, par)] = find(u, par);
        link[u][v]++; link[v][u]++;
        pre = es[i].w;
    }
    int flg = find(0, fa);
    for(int i = 1; i < n; i++){
        if(find(i, fa) != flg)return 0;
    }
    return (ret+mod)%mod;
}
