///暂时只更新(点权修改,链上点权值和/最大值询问),例题bzoj1036
const int maxn = 1e5+10;
///树链剖分模板
/************************************************/
int val_p[maxn], val_e[maxn], ///点权与边权
        to[maxn*2], nxt[maxn*2],head[maxn*2], tot;
void tree_init(){
    tot = 0;
    memset(head, 0, sizeof(head));
}
void add_edg(int u, int v, int w = 0){
    tot++; val_e[tot] = w; to[tot] = v;
    nxt[tot] = head[u]; head[u] = tot;
}
void read_edg(int op = 1){///op=1 --> 双向边; op=0 --> 单向边
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add_edg(u, v, w);
    if(op) add_edg(v, u, w);
}
int tid[maxn],   ///dfs序/tid[i]-->节点i在线段树中的位置
    rk[maxn],    ///rk[i]-->dfs序第i个在树中的节点编号
    top[maxn],   ///所在链顶点
    sz[maxn],    ///子树size
    son[maxn],   ///重儿子
    dep[maxn],   ///深度
    fa[maxn],    ///父节点
    idx;         ///dfs序计数器
void dfs1(int u, int f){
    ///更新dep[u], fa[u], sz[u], son[u]
    dep[u] = dep[f]+1;
    fa[u] = f;
    sz[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if(son[u] < 0 || sz[v] > sz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u, int tp){
    ///更新top[u], tid[u], rk[u]
    top[u] = tp;
    tid[u] = idx;
    rk[idx++] = u;
    if(son[u] >= 0) dfs2(son[u], tp);
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
void chain_div(int _n, int rt = 1){///rt取决于题目是否为有根树
    memset(son, -1, sizeof(int)*(_n+5));
    dep[rt] = idx = 0;
    dfs1(rt, rt);
    dfs2(rt, rt);
}
/*************************************************/
///线段树和调用部分仅作参考，赛场上自行发挥
int mx[maxn*3], val[maxn], n, sum[maxn*3];
void pick_up(int rt){
    mx[rt] = max(mx[lson], mx[rson]);
    sum[rt] = sum[lson] + sum[rson];
}
void build(int rt = 0, int l = 0, int r = n-1){
    if(l == r){
        mx[rt] = sum[rt] = val[l];
        return;
    }
    build(lson, l, mid);
    build(rson, mid+1, r);
    pick_up(rt);
}
void update(int x, int v, int rt = 0, int l = 0, int r = n-1){
    if(l > x || r < x) return;
    if(l == x && r == x){
        mx[rt] = sum[rt] = v;
        return;
    }
    update(x, v, lson, l, mid);
    update(x, v, rson, mid+1, r);
    pick_up(rt);
}
inline pii add(pii a, pii b){
    return pii(max(a.fi,b.fi), a.se+b.se);
}
pii query(int x, int y, int rt = 0, int l = 0, int r = n-1){
    if(l > y || r < x) return mk(-INF, 0);
    if(l >= x && r <= y){
        return mk(mx[rt], sum[rt]);
    }
    pii a = query(x, y, lson, l, mid),
        b = query(x, y, rson, mid+1, r);
    return add(a,b);
}
pii solve(int u, int v){
    pii ans = mk(-INF, 0);
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        ans = add(ans, query(tid[top[u]], tid[u]));
        u = fa[top[u]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    ans = add(ans, query(tid[u], tid[v]));
    return ans;
}
int main(){
    tree_init();
    sc(n);
    for(int i = 1; i < n; i++){
        int u, v; sc(u); sc(v);
        add_edg(u,v);
        add_edg(v,u);
    }
    for(int i = 1; i <= n; i++)
        sc(val_p[i]);
    chain_div(n);
    for(int i = 1; i <= n; i++)
        val[tid[i]] = val_p[i];
    build();
    int q; sc(q);
    while(q--){
        char s[5];
        int x,y;
        scanf("%s%d%d", s, &x, &y);
        if(s[1] == 'M'){
            printf("%d\n", solve(x,y).fi);
        }else if(s[1] == 'H'){
            update(tid[x], y);
        }else{
            printf("%d\n", solve(x,y).se);
        }
    }
    return 0;
}
