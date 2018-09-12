#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 5e2+10;
int G[maxn][maxn];
int dis[maxn], id[maxn];
int n, m;

int StoerWagner(int n)
{
    int ret = INF;
    for(int i = 0; i < n; i++)id[i] = i;
    while(n > 1){
        memset(dis, 0, sizeof(dis));
        int k = 0;
        for(int i = 1; i < n; i++){
            swap(id[k], id[i-1]);
            for(int j = k = i; j < n; j++){
                dis[id[j]] += G[id[i-1]][id[j]];
                if(dis[id[j]] > dis[id[k]])k = j;
            }
        }
        ret = min(ret, dis[id[k]]);
        int s = id[n-2], t = id[n-1];
        for(int i = 0; i < n-2; i++){
            int u = id[i];
            G[u][s] = G[s][u] += G[u][t];
        }
        id[k] = id[n--];
    }
    return ret;
}
