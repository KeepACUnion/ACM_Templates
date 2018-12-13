struct SA{
    int s[maxn], sa[maxn], t[maxn], t2[maxn], c[maxn], 
        rk[maxn], height[maxn];
    void build_sa(int m, int n){///s[i] in {1,m-1}, length is n
    	///add 0 at end of string
        s[n++]=0;
        int *x=t, *y=t2;
        for(int i=0;i<m;i++) c[i]=0;
        for(int i=0;i<n;i++) c[x[i]=s[i]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;~i;i--) sa[--c[x[i]]]=i;
        for(int k=1;k<=n;k<<=1){
            int p=0;
            for(int i=n-k;i<n;i++) y[p++]=i;
            for(int i=0;i<n;i++) if(sa[i]>=k)
                y[p++] = sa[i]-k;
            for(int i=0;i<m;i++) c[i]=0;
            for(int i=0;i<n;i++) c[x[y[i]]]++;
            for(int i=1;i<m;i++) c[i]+=c[i-1];
            for(int i=n-1;~i;i--) sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1; x[sa[0]]=0;
            for(int i=1;i<n;i++)
                x[sa[i]] = y[sa[i-1]]==y[sa[i]] &&
                    y[sa[i-1]+k]==y[sa[i]+k] ? p-1 : p++;
            if(p>=n) break;
            m = p;
        }
        int k=0;
        for(int i=0;i<n;i++) rk[sa[i]]=i;
        for(int i=0;i<n;i++){
            if(k) k--;
            if(rk[i]==0) continue;
            int j=sa[rk[i]-1];
            while(s[i+k]==s[j+k]) k++;
            height[rk[i]]=k;
        }
    }
    int dp[maxn][30];
    void initrmq(int n){
        for(int i=1;i<=n;i++) dp[i][0]=height[i];
        for(int j=1;(1<<j)<=n;j++) for(int i=1;i+(1<<j)-1<=n;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
    int rmq(int l, int r){
        int k=31-__builtin_clz(r-l+1);
        return min(dp[l][k], dp[r-(1<<k)+1][k]);
    }
    int lcp(int a, int b){
        a = rk[a], b = rk[b];
        if(a>b) swap(a,b);
        return rmq(a+1,b);
    }
};
