//hdu6184
//计算每条边上的三元环的个数
#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int n, m;
const int maxn = 100000 + 100;
struct edge
{
    int u, v;
}es[maxn * 2];
int deg[maxn];
int cost[maxn * 2];
vector<vector<pii> > v(maxn);
pii rep[maxn];

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        memset(deg, 0, sizeof(deg));
        memset(cost, 0, sizeof(cost));
        memset(rep, 0, sizeof(rep));
        for(int i = 0; i <= n; i++)v[i].clear();
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &es[i].u, &es[i].v);
            deg[es[i].u]++, deg[es[i].v]++;
        }
        for(int i = 1; i <= m; i++){
            if((deg[es[i].u] < deg[es[i].v]) || (deg[es[i].u] == deg[es[i].v] && es[i].u < es[i].v)){
                v[es[i].u].pb(mk(es[i].v, i));
            }
            else v[es[i].v].pb(mk(es[i].u, i));
        }
        for(int i = 1; i <= m; i++){
            int p, q;
            p = es[i].u, q = es[i].v;
            for(int j = 0; j < (int)v[p].size(); j++){
                rep[v[p][j].fi] = mk(i, v[p][j].se);
            }
            for(int j = 0; j < (int)v[q].size(); j++){
                if(rep[v[q][j].fi].fi == i){
                    cost[i]++;
                    cost[v[q][j].se]++;
                    cost[rep[v[q][j].fi].se]++;
                    //printf("%d %d %d\n", i, v[q][j].se, rep[v[q][j].fi].se);
                }
            }
        }
        ll ans = 0;
        for(int i = 1; i <= m; i++){
            ans += (ll)cost[i] * (cost[i] - 1) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
