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
int n, q;
const int maxn = 1e5 + 10;
const int b = 1289;
int nums[maxn];
int A[maxn];
vector<int> bucket[maxn];

int upb(int id, int x)
{
    int l = 0, r = bucket[id].size() - 1;
    int ans = bucket[id].size();
    while(l <= r){
        int mid = (l + r) / 2;
        if(bucket[id][mid] > x){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}

void solve()
{
    //int b = sqrt(maxn * log2(maxn));
    //if(!b)b++;
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        bucket[i / b].pb(A[i]);
        nums[i] = A[i];
    }
    sort(nums, nums + n);
    for(int i = 0; i < n / b; i++)sort(ALL(bucket[i]));
    for(int i = 0; i < q; i++){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l--;
        int ls = 0, rs = n - 1, ans = 0;
        while(ls <= rs){
            int mid = (ls + rs) / 2;
            int x = nums[mid];
            int t1 = l, t2 = r, c = 0;
            while(t1 < t2 && t1 % b != 0)if(A[t1++] <= x)c++;
            while(t1 < t2 && t2 % b != 0)if(A[--t2] <= x)c++;
            while(t1 < t2){
                int nb = t1 / b;
                c += upb(nb, x);
                t1 += b;
            }
            //if(i == 2)cout << c << endl;
            if(c >= k){
                rs = mid - 1;
                ans = mid;
            }
            else ls = mid + 1;
        }
        printf("%d\n", nums[ans]);
    }
}

int main()
{
    //frein;
    //freout;
    sc(n);sc(q);
    solve();
	return 0;
}


