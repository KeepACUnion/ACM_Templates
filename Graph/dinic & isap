#include<bits/stdc++.h>
using namespace std;

struct edge{int st,ed,fl,ne;}x[maxm];

queue<int>q;
int d[maxn],g[maxn],bj[maxn],now[maxn];

/*Dinic*/
bool bfs()
{
	memset(d,0,sizeof(d));
	q.push(1);d[1]=1;
	while(!q.empty())
	{
		int t=q.front();q.pop();
		for(int i=bj[t];i!=-1;i=x[i].ne)
			if(!d[x[i].ed]&&x[i].fl)
				q.push(x[i].ed),d[x[i].ed]=d[t]+1;
	}
	return d[n]!=0;
}

int dfs(int t,int pre)
{
	if(t==n)return pre;
	for(int &i=now[t];i!=-1;i=x[i].ne)
	{
		if(!x[i].fl||d[x[i].ed]!=d[t]+1||!(k=dfs(x[i].ed,min(x[i].fl,pre))))continue;
		x[i].fl-=k,x[i^1].fl+=k;
		return k;
	}
	return 0;
}

int main()
{
	...
	while(bfs())
	{
		for(int i=1;i<=n;i++)now[i]=bj[i];
		do ans+=(t=dfs(1,inf));
		while(t!=0);
	}
	return 0;
}

/*ISAP

int dfs(int t,int pre)
{
    if(t==n)return pre;
    int mn=n-1,res=pre,k;
    for(int i=bj[t];i!=-1;i=x[i].ne)
    {
        if(!x[i].fl)continue;
        if(d[t]==d[x[i].ed]+1)
        {
            k=dfs(x[i].ed,min(res,x[i].fl));
            x[i].fl-=k;
            x[i^1].fl+=k;
            res-=k;
            if(d[1]>=n)return pre-res;
            if(!res)break;
        }
        mn=min(mn,d[x[i].ed]);
    }
    if(res==pre)
    {
        if(!(--g[d[t]]))d[1]=n;
        g[d[t]=mn+1]++;
    }
    return pre-res;
}

int main()
{
	...
	g[0]=n;
    while(d[1]<n)ans-=dfs(1,inf);

	return 0;
}
*/
