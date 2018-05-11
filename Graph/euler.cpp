#include <stack>
#include <vector>
using namespace std;
#define pb push_back
int n, m;
const int maxn = 1e5+10;
vector<int> G[maxn];
stack<int> sk;
vector<int> ans;

void euler(int st)//调用后会修改原图
{
    sk.push(st);
    while(!sk.empty()){
        int u = sk.top();
        bool flg = 0;
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i];
            if(v != -1){
                flg = 1;
                G[u][i] = -1;
                sk.push(v);
                break;
            }
        }
        if(!flg){
            ans.pb(u);
            sk.pop();
        }
    }
}
