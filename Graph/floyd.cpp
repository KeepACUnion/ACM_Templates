#include <algorithm>
using namespace std;
const int maxn = 1e3+10;
const int INF = 0x3f3f3f3f;
int mp[maxn][maxn];//原始距离
int dis[maxn][maxn];//最短路
int n;
int floyd()
{
    int ret = INF;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i < k; i++){
            for(int j = i+1; j < k; j++){
                ret = min(ret, dis[i][j]+mp[i][k]+mp[k][j]);
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    return ret;
}
