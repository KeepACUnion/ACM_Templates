const int maxn = 1e4+10;
int n, head[maxn], val[maxn*2], nxt[maxn*2],
    to[maxn*2], tot;
void add_edg(int u, int v, int w){
    tot++; nxt[tot] = head[u]; to[tot] = v;
    val[tot] = w; head[u] = tot;
}
int root, mx[maxn], sz[maxn], done[maxn];
void get_root(int u, int f, int tree_size){
    mx[u] = 0; sz[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == f || done[v]) continue;
        get_root(v, u, tree_size);
        sz[u] += sz[v];
        mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], tree_size-sz[u]);
    if(mx[u] < mx[root]) root = u;
}
void solve(int u, int tree_size){
    root = 0;
    mx[root] = n;
    get_root(u, 0, tree_size);
    u = root;
    done[u] = 1;
    /*********/
    ///TODO
    /*********/
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(done[v]) continue;
        /***************/
        ///TODO
        /**************/
        solve(v, sz[v]);
    }
}
void init(){
    memset(done, 0, sizeof(done));
    memset(head, 0, sizeof(head));
    tot = 0;
    ///TODO
}
