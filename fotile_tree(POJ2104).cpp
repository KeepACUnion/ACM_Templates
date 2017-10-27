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
const int maxn = 2e6 + 10;
int cnt;
int a[maxn];
int b[maxn];
int ls[maxn];
int rs[maxn];
int sum[maxn];
int root[maxn];

void build(int &node, int l, int r)
{
    node = cnt++;
    sum[node] = 0;
    if(l == r)return;
    int m = (l + r) / 2;
    build(ls[node], l, m);
    build(rs[node], m+1, r);
}

void update(int &node, int l, int r, int last, int val)
{
    node = ++cnt;
    ls[node] = ls[last];
    rs[node] = rs[last];
    sum[node] = sum[last] + 1;
    if(l == r)return;
    int m = (l + r) / 2;
    if(val <= m)update(ls[node], l, m, ls[last], val);
    else update(rs[node], m+1, r, rs[last], val);
}

int query(int ss, int tt, int l, int r, int k)
{
    if(l == r)return l;
    int m = (l + r) / 2;
    int cnt = sum[ls[tt]] - sum[ls[ss]];
    if(k <= cnt)return query(ls[ss], ls[tt], l, m, k);
    else return query(rs[ss], rs[tt], m+1, r, k-cnt);
}

int main()
{
    int n, q;
    sc(n);sc(q);
    for(int i = 1; i <= n; i++){
        sc(b[i]);
        a[i] = b[i];
    }
    sort(a + 1, a + n + 1);
    int sz = unique(a + 1, a + n + 1) - (a + 1);
    for(int i = 1; i <= n; i++){
        b[i] = lower_bound(a + 1, a + sz + 1, b[i]) - a;
    }
    build(root[0], 1, sz);
    for(int i = 1; i <= n; i++){
        update(root[i], 1, sz, root[i-1], b[i]);
    }
    for(int i = 0; i < q; i++){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int ans = query(root[l-1], root[r], 1, sz, k);
        printf("%d\n", a[ans]);
    }
	return 0;
}


