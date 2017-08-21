void init(int n_)
{
    n = 1;
    while(n < n_)n *= 2;
    for(int i = 0; i < n; i++){
        if(i < n_)tree[n - 1 + i] = a[i];
        else tree[n - 1 + i] = 0;
    }
    for(int i = n - 2; i >= 0; i--){
        tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
    }
    for(int i = 0; i < 2 * n - 1; i++)tag[i] = 0;
}
void update(int a, int b, int k, int l, int r, ll val)
{
    if(l >= b || r <= a)return;
    if(l >= a && r <= b){
        tag[k] += val;
        return;
    }
    tree[k] += (min(r, b) - max(l, a)) * val;
    update(a, b, k * 2 + 1, l, (l + r) / 2, val);
    update(a, b, k * 2 + 2, (l + r) / 2, r, val);
}
ll query(int a, int b, int k, int l, int r)
{
    if(l >= b || r <= a)return 0;
    if(l >= a && r <= b){
        return tree[k] + tag[k] * (r - l);
    }
    ll res = (min(r, b) - max(l, a)) * tag[k];
    res += query(a, b, k * 2 + 1, l, (l + r) / 2);
    res += query(a, b, k * 2 + 2, (l + r) / 2, r);
    return res;
}


//区间覆盖
void build(int a, int b, int k, int l, int r)
{
    if(l == r - 1){
        tree[k].ls = tree[k].rs = tree[k].ms = r - l;
        return;
    }
    build(a, b, k * 2 + 1, l, (l + r) / 2);
    build(a, b, k * 2 + 2, (l + r) / 2, r);
    tree[k].ls = tree[k].rs = tree[k].ms = r - l;
}
void update(int t, int k, int l, int r, int val)
{
    if(l == r - 1){
        if(val == 0){
            tree[k].ls = tree[k].rs = tree[k].ms = 0;
        }
        else if(val == 1){
            tree[k].ls = tree[k].rs = tree[k].ms = 1;
        }
        return;
    }
    int m = (l + r) / 2;
    if(t < m)update(t, k * 2 + 1, l, (l + r) / 2, val);
    else update(t, k * 2 + 2, (l + r) / 2, r, val);
    tree[k].ls = tree[k * 2 + 1].ls;
    tree[k].rs = tree[k * 2 + 2].rs;
    tree[k].ms = max(tree[k * 2 + 1].ms, tree[k * 2 + 2].ms);
    tree[k].ms = max(tree[k].ms, tree[k * 2 + 1].rs + tree[k * 2 + 2].ls);
    if(tree[k * 2 + 1].ls == m - l){
        tree[k].ls += tree[k * 2 + 2].ls;
    }
    if(tree[k * 2 + 2].rs == r - m){
        tree[k].rs += tree[k * 2 + 1].rs;
    }
}
int query(int t, int k, int l, int r)
{
    if(tree[k].ms == 0 || tree[k].ms == r - l || l == r - 1){
        return tree[k].ms;
    }
    int m = (l + r) / 2;
    if(t < m){
        if(t >= m -  tree[k * 2 + 1].rs){
            return query(t, k * 2 + 1, l, m) + query(m, k * 2 + 2, m, r);
        }
        else return query(t, k * 2 + 1, l, m);
    }
    else{
        if(t < m + tree[k * 2 + 2].ls){
            return query(m - 1, k * 2 + 1, l, m) + query(t, k * 2 + 2, m, r);
        }
        else return query(t, k * 2 + 2, m, r);
    }
}


//矩形周长并
int cnt;
struct node
{
    int x, y1, y2, cx, cy1, cy2, k;
}line[10010];
int x[10010];
int y[10010];
struct seg
{
    int cover, numseg, len;
    bool lcover, rcover;
}tree[10010 * 4];
int unq(int a[])
{
    sort(a, a + cnt);
    int m = 1;
    for(int i = 1; i < cnt; i++){
        if(a[i] > a[i - 1])a[m++] = a[i];
    }
    return m;
}
bool cmp(node a, node b)
{
    return a.x < b.x;
}
void build(int a, int b, int k, int l, int r)
{
    tree[k].len = tree[k].cover = tree[k].numseg = 0;
    if(l == r - 1)return;
    build(a, b, k * 2 + 1, l, (l + r) / 2);
    build(a, b, k * 2 + 2, (l + r) / 2, r);
}
void pushup(int k, int l, int r)
{
    if(tree[k].cover){
        tree[k].len = y[r] - y[l];
        tree[k].numseg = 1;
        tree[k].lcover = tree[k].rcover = 1;
    }
    else if(l == r - 1){
        tree[k].len = 0;
        tree[k].numseg = 0;
        tree[k].lcover = tree[k].rcover = 0;
    }
    else{
        tree[k].len = tree[k * 2 + 1].len + tree[k * 2 + 2].len;
        tree[k].numseg = tree[k * 2 + 1].numseg + tree[k * 2 + 2].numseg;
        tree[k].lcover = tree[k * 2 + 1].lcover;
        tree[k].rcover = tree[k * 2 + 2].rcover;
        if(tree[k * 2 + 1].rcover && tree[k * 2 + 2].lcover)tree[k].numseg--;
    }
}
void update(int a, int b, int k, int l, int r, int val)
{
    if(l >= b || r <= a)return;
    else if(l >= a && r <= b){
        tree[k].cover += val;
        pushup(k, l, r);
        return;
    }
    update(a, b, k * 2 + 1, l, (l + r) / 2, val);
    update(a, b, k * 2 + 2, (l + r) / 2, r, val);
    pushup(k, l, r);
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        cnt = 0;
        for(int i = 0; i < n; i++){
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            line[cnt].x = x1, line[cnt].y1 = y1, line[cnt].y2 = y2, line[cnt].k = 1;
            x[cnt] = x1;
            y[cnt] = y1;
            cnt++;
            line[cnt].x = x2, line[cnt].y1 = y1, line[cnt].y2 = y2, line[cnt].k = -1;
            x[cnt] = x2;
            y[cnt] = y2;
            cnt++;
        }
        int mx = unq(x);
        int my = unq(y);
        sort(line, line + cnt, cmp);
        for(int i = 0; i < cnt; i++){
            line[i].cx = lower_bound(x, x + mx, line[i].x) - x;
            line[i].cy1 = lower_bound(y, y + my, line[i].y1) - y;
            line[i].cy2 = lower_bound(y, y + my, line[i].y2) - y;
        }
        int ans = 0, pre = 0;
        my--;
        build(0, my, 0, 0, my);
        for(int i = 0; i < cnt - 1; i++){
            update(line[i].cy1, line[i].cy2, 0, 0, my, line[i].k);
            ans += tree[0].numseg * 2 * (line[i + 1].x - line[i].x);
            ans += abs(tree[0].len - pre);
            pre = tree[0].len;
        }
        update(line[cnt - 1].cy1, line[cnt - 1].cy2, 0, 0, my, line[cnt - 1].k);
        ans += abs(tree[0].len - pre);
        printf("%d\n", ans);
    }
    return 0;
}


//矩形面积交
int cnt;
struct seg
{
    double x, y1, y2;
    int cx, cy1, cy2, k;
}line[2010];
struct node
{
    double len1, len2;
    int cover;
}tree[2010 * 4];
double x[2010];
double y[2010];
int unq(double a[])
{
    sort(a, a + cnt);
    int m = 1;
    for(int i = 1; i < cnt; i++){
        if(a[i] - a[i - 1] > eps)a[m++] = a[i];
    }
    return m;
}
bool cmp(seg a, seg b)
{
    return a.x < b.x;
}
void build(int a, int b, int k, int l, int r)
{
    tree[k].cover = 0;
    tree[k].len1 = 0;
    tree[k].len2 = 0;
    if(l == r - 1)return;
    build(a, b, k * 2 + 1, l, (l + r) / 2);
    build(a, b, k * 2 + 2, (l + r) / 2, r);
}
void pushdown(int k, int l, int r)
{
    if(tree[k].cover){
        tree[k].len1 = y[r] - y[l];
    }
    else if(l == r - 1)tree[k].len1 = 0;
    else tree[k].len1 = tree[k * 2 + 1].len1 + tree[k * 2 + 2].len1;
    if(tree[k].cover >= 2){
        tree[k].len2 = y[r] - y[l];
    }
    else if(l == r - 1)tree[k].len2 = 0;
    else if(tree[k].cover == 1)tree[k].len2 = tree[k * 2 + 1].len1 + tree[k * 2 + 2].len1;
    else tree[k].len2 = tree[k * 2 + 1].len2 + tree[k * 2 + 2].len2;
}
void update(int a, int b, int k, int l, int r, int val)
{
    if(l >= b || r <= a)return;
    else if(l >= a && r <= b){
        tree[k].cover += val;
        pushdown(k, l, r);
        return;
    }
    update(a, b, k * 2 + 1, l, (l + r) / 2, val);
    update(a, b, k * 2 + 2, (l + r) / 2, r, val);
    pushdown(k, l, r);
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        cnt = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            double x1, x2, y1, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            line[cnt].x = x1, line[cnt].y1 = y1, line[cnt].y2 = y2, line[cnt].k = 1;
            x[cnt] = x1, y[cnt] = y1;
            cnt++;
            line[cnt].x = x2, line[cnt].y1 = y1, line[cnt].y2 = y2, line[cnt].k = -1;
            x[cnt] = x2, y[cnt] = y2;
            cnt++;
        }
        int mx = unq(x);
        int my = unq(y);
        sort(line, line + cnt, cmp);
        for(int i = 0; i < cnt; i++){
            line[i].cx = lower_bound(x, x + mx, line[i].x) - x;
            line[i].cy1 = lower_bound(y, y + my, line[i].y1) - y;
            line[i].cy2 = lower_bound(y, y + my, line[i].y2) - y;
        }
        my--;
        double ans = 0;
        build(0, my, 0, 0, my);
        for(int i = 0; i < cnt - 1; i++){
            update(line[i].cy1, line[i].cy2, 0, 0, my, line[i].k);
            ans += tree[0].len2 * (x[line[i + 1].cx] - x[line[i].cx]);
        }
        printf("%.2f\n", ans);
    }
    return 0;
}


//矩形面积交
struct seg
{
    double x, y1, y2, k;
    int cx, cy1, cy2;
}line[220];
double x[220];
double y[220];
int cnt;
struct node
{
    double len;
    int cover;
}tree[220 * 4];
int unique_x()
{
    sort(x, x + cnt);
    int m = 1;
    for(int i = 1; i < cnt; i++){
        if(x[i] - x[i - 1] > eps)x[m++] = x[i];
    }
    return m;
}
int unique_y()
{
    sort(y, y + cnt);
    int m = 1;
    for(int i = 1; i < cnt; i++){
        if(y[i] - y[i - 1] > eps)y[m++] = y[i];
    }
    return m;
}
bool cmp(seg a, seg b)
{
    return a.x < b.x;
}
void build(int a, int b, int k, int l, int r)
{
    tree[k].len = 0;
    tree[k].cover = 0;
    //printf("%f%d\n", tree[k].len, tree[k].cover);
    if(l == r - 1)return;
    build(a, b, k * 2 + 1, l, (l + r) / 2);
    build(a, b, k * 2 + 2, (l + r) / 2, r);
}
void pushup(int k, int l, int r)
{
    if(tree[k].cover){
        tree[k].len = y[r] - y[l];
    }
    else if(l == r - 1)tree[k].len = 0;
    else tree[k].len = tree[k * 2 + 1].len + tree[k * 2 + 2].len;
}
void update(int a, int b, int k, int l, int r, int val)
{
    if(l >= b || r <= a)return;
    if(l >= a && r <= b){
        tree[k].cover += val;
        pushup(k, l, r);
        return;
    }
    update(a, b, k * 2 + 1, l, (l + r) / 2, val);
    update(a, b, k * 2 + 2, (l + r) / 2, r, val);
    pushup(k, l, r);
}
int main()
{
    int n, kase = 1;
    while(scanf("%d", &n) != EOF && n){
        cnt = 0;
        for(int i = 0; i < n; i++){
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            line[cnt].x = x1, line[cnt].y1 = y1, line[cnt].y2 = y2, line[cnt].k = 1;
            x[cnt] = x1;
            y[cnt] = y1;
            cnt++;
            line[cnt].x = x2, line[cnt].y1 = y1, line[cnt].y2 = y2, line[cnt].k = -1;
            x[cnt] = x2;
            y[cnt] = y2;
            cnt++;
        }
        int mx = unique_x();
        int my = unique_y();
        sort(line, line + cnt, cmp);
        for(int i = 0; i < cnt; i++){
            line[i].cx = lower_bound(x, x + mx, line[i].x) - x ;
            line[i].cy1 = lower_bound(y, y + my, line[i].y1) - y;
            line[i].cy2 = lower_bound(y, y + my, line[i].y2) - y;
        }
        my--;
        build(0, my, 0, 0, my);
        double ans = 0;
        for(int i = 0; i < cnt - 1; i++){
            update(line[i].cy1, line[i].cy2, 0, 0, my, line[i].k);
            ans += tree[0].len * (x[line[i + 1].cx] - x[line[i].cx]);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", kase++, ans);
    }
    return 0;
}
