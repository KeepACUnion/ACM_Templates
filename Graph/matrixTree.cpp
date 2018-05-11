#include <vector>
using namespace std;
typedef long long ll;
#define ABS(x) ((x)>=0?(x):(-(x)))
const int maxn = 110;
vector<int> G[maxn];
int n;
ll det()
{
    ll ret = 1;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            while(G[j][i]){
                ll t = G[i][i]/G[j][i];
                for(int k = i; k < n; k++){
                    G[i][k] -= G[j][k]*t;
                }
                for(int k = i; k < n; k++){
                    swap(G[i][k], G[j][k]);
                }
                ret = -ret;
            }
        }
        if(!G[i][i])return 0;
        ret *= G[i][i];
    }
    return ABS(ret);
}
