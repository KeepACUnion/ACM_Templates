/************三维偏序问题**************/
const int maxn = 1e5+100;
int n,bit[maxn],ans[maxn];
struct que{
    int a,b,c,idx;
} q[maxn], tmp[maxn];
int cmp(que a, que b){
    if(a.a != b.a) return a.a < b.a;
    else if(a.b != b.b) return a.b < b.b;
    else return a.c < b.c;
}
int cmp1(que a, que b){
    if(a.b != b.b) return a.b < b.b;
    else return a.c < b.c;
}
void add(int x, int v){for(int i=x;i<maxn;i+=i&-i)bit[i]+=v;}
void reset(int p){for(int i=p;i<maxn;i+=i&-i)bit[p]=0;}
int sum(int x){
    int res = 0;
    for(int i=x;i>0;i-=i&-i)res+=bit[i];
    return res;
}
void cdq(int l, int r){
    /*l,r为第一维,分治中对第二维进行排序，第三维bit维护*/
    if(l == r)  return;
    int m = (l+r)/2;
    cdq(l,m); cdq(m+1,r);
    for(int i = l; i <= r; i++) tmp[i] = q[i];
    sort(tmp+l,tmp+m+1,cmp1);
    sort(tmp+m+1,tmp+r+1,cmp1);
    /*处理[l,m]之中的修改对[m+1,r]中的询问的影响*/
    for(int i=m+1,j=l;i<=r;i++){
        while(j<=m&&tmp[j].b<=tmp[i].b) add(tmp[j++].c,1);
        ans[tmp[i].idx]+=sum(tmp[i].c);
    }
    /*reset bit*/
    for(int i = l; i <= m; i++) reset(tmp[i].c);
}
int main(){
    int T; sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &q[i].a, &q[i].b, &q[i].c);
            q[i].idx = i;
        }
        sort(q, q+n,cmp);
        memset(ans, 0, sizeof(ans));
        cdq(0, n-1);
        for(int i = n-2; i >= 0; i--){
            if(q[i].a == q[i+1].a && q[i].b == q[i+1].b && q[i].c == q[i+1].c)
                ans[q[i].idx] = ans[q[i+1].idx];
        }
        for(int i = 0; i < n; i++) printf("%d\n", ans[i]);
    }
    return 0;
}
