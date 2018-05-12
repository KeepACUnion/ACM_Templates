#include <vector>
using namespace std;
const int maxn = 1e3+10;
vector<int> G[maxn];
int mat[maxn];
bool vis[maxn];
int n;
bool dfs(int x){  
    for (int i = 0; i < (int)G[x].size(); i++){
        int v = G[x][i];
        if(!vis[v]){
            vis[v] = 1;  
            if (mat[v] == 0 || dfs(mat[v])){   
                mat[v] = x;  
                return true;  
            }  
        }  
    }  
    return false;  
}
int solve()
{
    int ans = 0;
    for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        if(dfs(i))ans++;
    }
    return ans;
}
