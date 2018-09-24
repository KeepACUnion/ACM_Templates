#include <cstdio>
using namespace std;
const int maxn = 1e5+10;
const int logq = 20;
int root[maxn], ls[maxn*logq], rs[maxn*logq], sum[maxn*logq];
int n, cnt;
void build(int &rt, int l, int r)
{
    rt = cnt++;
    sum[rt] = 0;
    if(l == r-1)return;
    int m = (l+r)/2;
    build(ls[rt], l, m); build(rs[rt], m, r);
}

void update(int &rt, int l, int r, int last, int val)
{
    rt = ++cnt;
    ls[rt] = ls[last]; rs[rt] = rs[last]; sum[rt] = sum[last]+1;
    if(l == r-1)return;
    int m = (l+r)/2;
    if(val < m)update(ls[rt], l, m, ls[last], val);
    else update(rs[rt], m, r, rs[last], val);
}

int query(int ss, int tt, int l, int r, int k)//查询区间第k大
{
    if(l == r-1)return l;
    int m = (l+r)/2;
    int cnt = sum[ls[tt]] - sum[ls[ss]];
    if(k <= cnt)return query(ls[ss], ls[tt], l, m, k);
    else return query(rs[ss], rs[tt], m, r, k-cnt);
}
