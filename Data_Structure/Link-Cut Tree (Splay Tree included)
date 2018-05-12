#define rev(x) (swap(l[x],r[x]),b[x]^=1)
#define judge(x) (l[f[x]]==x||r[f[x]]==x)          
#define root(x) (access(x),modify(x),rev(x))       //LCA换根

int l[maxn],r[maxn],f[maxn],b[maxn],mx[maxn],v[maxn];
struct edge {int st,ed,a,b;} x[maxm];
 
bool find(int x,int y)    //判断是否在同一棵树
{
    while(f[x])x=f[x];
    while(f[y])y=f[y];
    return x==y;
}
 
void update(int t)        //更新splay上维护的信息
{
    mx[t]=max(mx[l[t]],mx[r[t]]);
    mx[t]=max(mx[t],v[t]);
}
 
void rotate(int x,int l[],int r[]) //splay旋转
{
    int t=f[x];
    f[l[t]=r[x]]=t;f[x]=f[t];
    if(judge(t))l[f[t]]==t?l[f[t]]=x:r[f[t]]=x;
    f[r[x]=t]=x;update(r[x]);
}
 
void deal(int x)            //splay标记下传
{
    if(judge(x))deal(f[x]);
    if(b[x])b[x]^=1,rev(l[x]),rev(r[x]);
}
 
void modify(int x)             //splay换根
{
    deal(x);
    while(judge(x))if(l[f[x]]==x)
    {
        if(judge(f[x])&&l[f[f[x]]]==f[x])
            rotate(f[x],l,r);
        rotate(x,l,r);
    }
    else
    {
        if(judge(f[x])&&r[f[f[x]]]==f[x])
            rotate(f[x],r,l);
        rotate(x,r,l);
    }
    update(x);
}
 
void access(int x)              //路径变重边
{
    for(int y=0;x;y=x,x=f[x]) 
        modify(x),l[x]=y,update(x);
}
 
void link(int x,int y)           //加边
{
    root(x);
    f[x]=y;
}
 
void cut(int x,int y)           //删边
{
    root(x);access(y);
    modify(y);
    f[x]=r[y]=0;
}

int quiry(int z,int y)           //查询两点之间权最大的点
{
    if(!find(z,y))return 2e9;
    root(z);
    access(y);modify(y);
    while(v[y]!=mx[y])
        y=(mx[l[y]]==mx[y]?l[y]:r[y]);
    return y;
}
