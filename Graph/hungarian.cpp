#include <vector>
#include <cstring>
using namespace std;
#define pb push_back
const int maxn = 5e2+10;
vector<int> G[maxn];
int mtx[maxn], mty[maxn];
bool vx[maxn], vy[maxn];
vector<int> pnt;//最小点覆盖
int n, m;
bool dfs(int u){
    vx[u] = 1;
    for(auto v : G[u]){
        if(!vy[v]){
            vy[v] = 1;  
            if (!mty[v] || dfs(mty[v])){   
                mty[v] = u;  
                return true;  
            }  
        }  
    }  
    return false;  
}
int solve()
{
    memset(mat, 0, sizeof(mat));
    int ans = 0;
    for(int i = 1; i <= n; i++){
        memset(vx, 0, sizeof(vx));
        memset(vy, 0, sizeof(vy));
        if(dfs(i))ans++;
    }
    memset(vx, 0, sizeof(vx));
    memset(vy, 0, sizeof(vy));
    for(int i = 1; i <= n; i++){
        if(!mtx[i])dfs(i);
    }
    for(int i = 1; i <= n; i++){
        if(!vx[i])vec.pb(i);
    }
    for(int i = 1; i <= m; i++){
        if(vy[i])vec.push(i);
    }
    return ans;
}
/*
hints
二分图中最小顶点覆盖等于最大匹配数
二分图中最小边覆盖=顶点数-最小顶点覆盖（最大匹配）
二分图中最大独立集+最小顶点覆盖（最大匹配）=顶点数
二分图的最大团=补图的最大独立集
最小路径覆盖=结点数-最大匹配数
*/
