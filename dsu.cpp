void init(int n)
{
	for(int i = 0; i <= n; i++){
		par[i] = i;
		val[i] = 0;
	}
}
int find(int x)
{
	if(par[x] != x){
		int f = par[x];
		par[x] = find(par[x]);
		val[x] += val[f];
	}
	return par[x];
}