/***四种操作:1.连x,y; 2.删掉边x,y; 3.询问x所在连通块的size; 4.询问x,y是否连通***/
/***大致思路:记录每个连边的持续时间*******************************************/
/************solve(l,r)碰到持续时间和l,r一样的操作就添加,回溯时撤销************/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
typedef pair<int,int> pii;
class jobs{
    public:
    int type;
    int x,y,l,r;
    jobs() {}
    jobs(int a,int b,int c,int d,int e) : type(a),x(b),y(c),l(d),r(e) {}
};
int n,m,x,y,op,ans[N],siz[N],f[N];
unordered_map <long long,int> pre;
vector<jobs> job;
int find(int x,vector<pii> &mem){
    if(x == f[x]) return x;
    mem.push_back(make_pair(x,f[x]));
    f[x] = find(f[x],mem);
    return f[x];
}
void deal(int l,int r,vector<jobs> &q){
    vector<pii> mem,mem2;
    for(jobs &p : q)
     if(p.l == l && p.r == r && p.type == 1){
         int x = p.x,y = p.y;
         if(find(x,mem) != find(y,mem)){
             mem.push_back(make_pair(f[x],f[f[x]]));
             mem2.push_back(make_pair(f[y],siz[f[y]]));
             siz[f[y]] += siz[f[x]];
             f[f[x]] = f[y];
         }
     }
    for(jobs &p : q)
     if(p.l == l && p.r == r && p.type != 1){
         int x = p.x,y = p.y;
         if(p.type == 2) ans[l] = siz[find(x,mem)];
         else ans[l] = N + (find(x,mem) == find(y,mem));
     }
    if(l != r){
        vector<jobs> q1,q2;
        int mid = (l+r)>>1;
        for(jobs &p : q)
         if(p.r <= mid) q1.push_back(p);
         else
          if(p.l <= mid){
              if(p.l == l && p.r == r) continue;
              q1.push_back(jobs(1,p.x,p.y,p.l,mid));
              q2.push_back(jobs(1,p.x,p.y,mid+1,p.r));
          }
          else q2.push_back(p);
        q.clear();
        deal(l,mid,q1);
        deal(mid+1,r,q2);
    }
    for(int i = mem.size()-1;i >= 0;i--) f[mem[i].first] = mem[i].second;
    for(int i = mem2.size()-1;i >= 0;i--) siz[mem2[i].first] = mem2[i].second;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++){
        scanf("%d",&op);
        if(op == 1){
            scanf("%d%d",&x,&y);
            if(x < y) swap(x,y);
            pre[1ll*x*N+y] = i;
        }
        if(op == 2){
            scanf("%d%d",&x,&y);
            if(x < y) swap(x,y);
            job.push_back(jobs(1,x,y,pre[1ll*x*N+y],i-1));
            pre.erase(pre.find(1ll*x*N+y));
        }
        if(op == 3){
            scanf("%d",&x);
            job.push_back(jobs(2,x,0,i,i));
        }
        if(op == 4){
            scanf("%d%d",&x,&y);
            job.push_back(jobs(3,x,y,i,i));
        }
    }
    for(pair<long long,int> v : pre)
        job.push_back(jobs(1,v.first/N,v.first % N,v.second,m));
    for(int i = 1;i <= n;i++)
        f[i] = i,siz[i] = 1;
    deal(1,m,job);
    for(int i = 1;i <= m;i++){
        if(!ans[i]) continue;
        if(ans[i] < N) cout<<ans[i]<<endl;
        else{
            if(ans[i] == N) cout<<"No"<<endl;
            else cout<<"Yes,cap"<<endl;
        }
    }
}
