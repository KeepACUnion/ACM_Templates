#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
#define mk make_pair
#define fi first
#define se second
const int maxn = 1e5+10;
vector<pii> G[maxn];
int cost[maxn];
void dijkstra(int s)
{
    memset(cost, 0x3f, sizeof(cost));
    cost[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(mk(0, s));
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        if(cost[p.se] < p.fi)continue;
        for(auto v : G[p.se]){
            if(cost[v.fi] > cost[p.se]+v.se){
                cost[v.fi] = cost[p.se]+v.se;
                pq.push(mk(cost[v.fi], v.fi));
            }
        }
    }
}
