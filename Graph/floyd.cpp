#include <algorithm>
using namespace std;
const int maxn = 5e2+10;
const int INF = 0x3f3f3f3f;
int G[maxn][maxn];//原始距离
int dis[maxn][maxn];//最短路
int road[maxn][maxn];
int path[maxn];//记录最小环路径(无法计算二元环)
int n, m, cnt;
void record(int s, int t)
{
    if(road[s][t]){
        record(s, road[s][t]);
        record(road[s][t], t);
    }
    else path[cnt++] = t;
}
int floyd()
{
    int ret = INF;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i < k; i++){
            for(int j = i+1; j < k; j++){
                if(dis[i][j] != INF && G[i][k] != INF && G[k][j] != INF && ret > dis[i][j]+G[i][k]+G[k][j]){ //注意溢出
                    ret = dis[i][j]+G[i][k]+G[k][j];
                    cnt = 0;
                    path[cnt++] = i;
                    record(i, j);
                    path[cnt++] = k;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][j] > dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                    road[i][j] = k;
                }
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    if(ret == INF)return -1; //无环
    return ret;
}
