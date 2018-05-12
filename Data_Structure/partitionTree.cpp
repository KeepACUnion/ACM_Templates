#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
const int maxd = 18;
typedef struct
{
    int num[maxn];
    int cnt[maxn];
}partition_tree;
partition_tree tree[maxd];
int sorted[maxn];
void build(int d, int l, int r)
{
    if(l == r)return;
    int m = (l + r) >> 1;
    int need = m - l + 1;
    for(int i = l; i <= r; i++)if(tree[d].num[i] < sorted[m])need--;
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
    else{
        newl = mid + 1 + (ql - l - ly);
        newr = newl + ((qr-ql+1)-tot) - 1;
        return query(d + 1, mid + 1, r,  newl, newr, k - tot);
    }
}
void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &tree[0].num[i]);
        sorted[i] = tree[0].num[i];
    }
    sort(sorted+1, sorted+n+1);
    build(0, 1, n);
    for(int i = 0; i < m; i++){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int ans = query(0, 1, n, l, r, k);
        printf("%d\n", ans);
    }
}
