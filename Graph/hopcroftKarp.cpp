#include <queue>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+10; 
vector<int> G[maxn];
int mtx[maxn], mty[maxn], dx[maxn], dy[maxn];
bool vis[maxn];
int dis, uN, vN;
bool bfs()
{
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    queue<int> q;
    for(int i = 1; i <= uN; i++){
        if(!mtx[i])q.push(i), dx[i] = 0;
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dx[u] > dis)break;
        for(auto v : G[u]){
            if(dy[v] == -1){
                dy[v] = dx[u]+1;
                if(!mty[v])dis = dy[v];
                else{
                    dx[mty[v]] = dy[v]+1;
                    q.push(mty[v]);
                }
            }
        }
    }
    return dis < INF;
}
bool dfs(int u)
{
    for(auto v : G[u]){
        if(!vis[v] && dy[v] == dx[u]+1){
            vis[v] = 1;
            if(dy[v] == dis && mty[v])continue;
            else if(!mty[v] || dfs(mty[v])){
                mty[v] = u, mtx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
int max_match()
{
    int ret = 0;
    while(bfs()){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= uN; i++){
            if(!mtx[i] && dfs(i))ret++;
        }
    }
    return ret;
}
