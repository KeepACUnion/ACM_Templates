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
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 0x3f3f3f3f;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5 + 10;
const int deep = 18;
typedef struct
{
    int num[maxn];
    int cnt[maxn];
}partition_tree;
partition_tree tree[deep];
int sorted[maxn];

void build(int d, int l, int r)
{
    if(l == r)return;
    int m = (l + r) >> 1;
    int need = m - l + 1;
    for(int i = l; i <= r; i++){
        if(tree[d].num[i] < sorted[m])need--;
    }
    int p = l, q = m + 1;
    for(int i = l, cnt = 0; i <= r; i++){
        int num = tree[d].num[i];
        if(num < sorted[m] || (num == sorted[m] && need)){
            if(num == sorted[m])need--;
            cnt++;
            tree[d + 1].num[p++] = num;
        }
        else tree[d + 1].num[q++] = num;
        tree[d].cnt[i] = cnt;
    }
    build(d + 1, l, m);
    build(d + 1, m + 1, r);
}

int query(int d, int l, int r, int ql, int qr, int k)
{
    if(l == r)return tree[d].num[l];
    int ly;
    if(l == ql)ly = 0;
    else ly = tree[d].cnt[ql-1];
    int tot = tree[d].cnt[qr] - ly;
    int newl, newr, mid = (l + r) / 2;
    if(tot >= k){
        newl = l + ly;
        newr = newl + tot - 1;
        return query(d + 1, l, mid, newl, newr, k);
    }
    else {
        newl = mid + 1 + (ql - l - ly);
        newr = newl + ((qr-ql+1)-tot) - 1;
        return query(d + 1, mid + 1, r,  newl, newr, k - tot);
    }
}

int main()
{
    int n, m;
    sc(n);sc(m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &tree[0].num[i]);
        sorted[i] = tree[0].num[i];
    }
    sort(sorted + 1, sorted + n + 1);
    build(0, 1, n);
    for(int i = 0; i < m; i++){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int ans = query(0, 1, n, l, r, k);
        printf("%d\n", ans);
    }
}


