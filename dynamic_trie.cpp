//hdu6183
//动态建trie
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
#define pr(x) cout<<"x:"<<x<<endl
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
const ll INF = 0x3f3f3f3f;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 15e6 + 10;
int tree[maxn];
int L[maxn];
int R[maxn];
int root[55];
int cnt = 0;
bool flag;

void init()
{
    fill(L, L + cnt + 1, 0);
    fill(R, R + cnt + 1, 0);
    fill(tree, tree + cnt + 1, 0);
    memset(root, 0, sizeof(root));
}

void update(int &k, int l, int r, int x, int y)
{
    if(!k){
        k = ++cnt;
        tree[k] = x;
    }
    tree[k] = min(tree[k], x);
    if(l == r - 1)return;
    int m = (l + r) / 2;
    if(y < m)update(L[k], l, m, x, y);
    else update(R[k], m, r, x, y);
}

void query(int k, int l, int r, int y1, int y2, int x)
{
    if(!k || flag || l >= y2 || r <= y1)return;
    if(l >= y1 && r <= y2){
        if(tree[k] <= x)flag = 1;
        return;
    }
    int m = (l + r) / 2;
    query(L[k], l, m, y1, y2, x);
    query(R[k], m, r, y1, y2, x);
}

int main()
{
    int opt;
    while(sc(opt) != EOF){
        if(opt == 0){
            init();
            cnt = 0;
        }
        if(opt == 1){
            int x, y, c;
            sc(x), sc(y), sc(c);
            update(root[c], 1, 1000001, x, y);
        }
        if(opt == 2){
            int x, y1, y2;
            sc(x), sc(y1), sc(y2);
            int ans = 0;
            for(int i = 0; i <= 50; i++){
                flag = 0;
                query(root[i], 1, 1000001, y1, y2 + 1, x);
                ans += flag;
            }
            printf("%d\n", ans);
        }
        if(opt == 3){
            break;
        }
    }
    return 0;
}
