int d[maxv];
int cost[maxv][maxv];
bool used[maxv];
int n;
void dijkstra(int s)
{
	for(int i = 1; i <= n; i++){
		d[i] = INF;
		used[i] = 0;
	}
	d[s] = 0;
	while(1){
		int v = -1;
		for(int u = 1; u <= n; u++){
			if(!used[u] && (v == -1 || d[u] < d[v]))v = u;
		}
		if(v == -1)break;
		used[v] = 1;
		for(int u = 1; u <= n; u++){
			d[u] = min(d[u], cost[v][u]);
		}
	}
}

struct edge
{
	int from, to, cost;
}es[maxe];
int n, E;
int d[maxn];
bool find_negative()
{
	memset(d, 0, sizeof(d));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < E; j++){
			edge e = es[j];
			if(e.to > d[e.from] + e.cost){
				d[e.to] = d[e.from] + e.cost;
				if(i == n - 1)return true;
			}
		}
	}
	return false;
}

void pqdijkstra(int s)
{
    priority_queue<pii, vector<pii> , greater<pii> > q;
    fill(d, d + V + 1, INF);
    d[s] = 0;
    q.push(mk(0, s));
    while(!q.empty()){
        pii p = q.top();
        q.pop();
        int v = p.se;
        if(d[v] < p.fi)continue;
        for(int i = head[v]; i != -1; i = pre[i]){
            edge e = es[i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                q.push(mk(d[e.to], e.to));
            }
        }
    }
}

void spfa(int s)
{
    memset(used, false, sizeof(used));
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(q.size()){
        int i = q.front();q.pop();
        used[i] = false;
        cnt[i]++;
        for(int j = head[i]; j != -1; j = es[j].next){
            int u = es[j].from, v = es[j].to, w = es[j].cost;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                if(used[v] == false && cnt[v] <= n){
                    used[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}