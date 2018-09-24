#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define pb push_back
#define ALL(x) x.begin(), x.end()
int n, m;
const int maxn = 1e5+10;
const int ST_SIZE = (1<<18)-1;
vector<int> dat[ST_SIZE];
int A[maxn];
int nums[maxn];
void init(int k, int l, int r)
{
    if(r-l == 1)dat[k].pb(A[l]);
    else{
        int lch = k*2+1, rch = k*2+2;
        init(lch, l, (l+r)/2);
        init(rch, (l+r)/2, r);
        dat[k].resize(r-l);
        copy(ALL(dat[lch]), dat[k].begin());
        copy(ALL(dat[rch]), dat[k].begin()+dat[lch].size());
        inplace_merge(dat[k].begin(), dat[k].begin()+dat[lch].size(), dat[k].end());
    }
}
int query(int i, int j, int x, int k, int l, int r)
{
    if(j <= l || r <= i)return 0;
    else if(i <= l && r <= j)return upper_bound(ALL(dat[k]), x)-dat[k].begin();
    else{
        int m = (l+r)>>1;
        int lc = query(i, j, x, k*2+1, l, m);
        int rc = query(i, j, x, k*2+2, m, r);
        return lc+rc;
    }
}
void solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        nums[i] = A[i];
    }
    sort(nums, nums+n);
    init(0, 0, n);
    for(int i = 0; i < m; i++){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l--;
        int ls = 0, rs = n-1, ans = 0;
        while(ls <= rs){
            int mid = (ls+rs) / 2;
            int c = query(l, r, nums[mid], 0, 0, n);
            if(c >= k){
                rs = mid-1;
                ans = mid;
            }
            else ls = mid+1;
        }
        printf("%d\n", nums[ans]);
    }
}
