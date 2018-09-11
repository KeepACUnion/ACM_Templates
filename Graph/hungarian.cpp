#include <vector>
#include <cstring>
using namespace std;
const int maxn = 5e2+10;
vector<int> G[maxn];
int mat[maxn];
bool vis[maxn];
int n;
bool dfs(int u){  
    for(auto v : G[u]){
        if(!vis[v]){
            vis[v] = 1;  
            if (mat[v] == 0 || dfs(mat[v])){   
                mat[v] = u;  
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
        memset(vis, 0, sizeof(vis));
        if(dfs(i))ans++;
    }
    return ans;
}
