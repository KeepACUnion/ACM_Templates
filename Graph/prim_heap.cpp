#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mk make_pair
const int maxn = 1e6+10;
vector<pii> G[maxn];
int cost[maxn];
bool vis[maxn];
int prim()
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    memset(cost, 0x3f, sizeof(cost));
    cost[1] = 0;
    pq.push(mk(0, 1));
    int ret = 0;
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        if(vis[p.se])continue;
        vis[p.se] = 1;
        ret += cost[p.se];
        for(int i = 0; i < (int)G[p.se].size(); i++){
            pii v = G[p.se][i];
            if(cost[v.fi] > v.se){
                cost[v.fi] = v.se;
                pq.push(mk(cost[v.fi], v.fi));
            } 
        }
    }
    return ret;
}
