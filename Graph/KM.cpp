#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 3e2+10;
int dx[maxn], dy[maxn], mat[maxn], pre[maxn], sl[maxn];
int G[maxn][maxn];
bool vis[maxn];
int n;
void bfs(int x)
{
    memset(vis, 0, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    memset(sl, 0x3f, sizeof(sl));
    int nx = 0, ny = 0;
    mat[ny] = x;
    do{
        nx = mat[ny]; vis[ny] = 1;
        int d = INF, t = 0;
        for(int i = 1;i <= n; i++)
            if(!vis[i]){
                int cost = dx[nx]+dy[i]-G[nx][i];
                if(cost < sl[i]){
                    sl[i] = cost; pre[i] = ny;
                }
                if(sl[i] < d){
                    d = sl[i]; t = i;
                }
            }
        for(int i = 0; i <= n; i++){
            if(vis[i])dx[mat[i]] -= d, dy[i] += d;
            else sl[i] -= d;
        }
        ny = t;
    }while(mat[ny]);
    while(ny)mat[ny] = mat[pre[ny]], ny = pre[ny];
}
int KM() {
    memset(mat, 0, sizeof(mat));
    memset(dy, 0, sizeof(dy));
    for(int i = 1; i <= n; i++){
        dx[i] = -INF;
        for(int j = 1; j <= n; j++)dx[i] = max(dx[i], G[i][j]);
    }
    for(int i = 1; i <= n; i++)bfs(i);
    int ret = 0;
    for(int i = 1; i <= n; i++)if(mat[i])ret += G[mat[i]][i];
    return ret;
}
