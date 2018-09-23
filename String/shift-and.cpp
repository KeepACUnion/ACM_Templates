/*
有一个文本串，它的长度为m(1≤m≤2000000)，现在想找出其中所有的符合特定模式的子串位置。 
符合特定模式是指，该子串的长度为n(1≤n≤500)，并且第i个字符需要在给定的字符集合Si中。 
因此，描述这一特定模式，共需要S1,S2,...,Sn这n个字符集合。每个集合的大小都在1∼62之间，其中的字符只为数字或大小写字母。 
*/
const int maxn = 2e6+10;

bitset<510> dp, b[63];
char s[maxn], t[66];
int n, tmp;

inline int id(char c){
    if(c >= 'a' && c <= 'z') return c-'a';
    else if(c >= 'A' && c <= 'Z') return c-'A'+26;
    else if(c >= '0' && c <= '9') return c-'0'+52;
    return 62;
}

int main(){
    //frein;
    while(fgets(s, maxn, stdin)){
        sc(n);
        dp.reset();
        for(int i = 0; i < 63; i++) b[i].reset();
        for(int i = 0; i < n; i++){
            sc(tmp);
            scanf("%s", t);
            int len = strlen(t);
            for(int j = 0; j < len; j++){
                b[id(t[j])].set(i);
            }
        }
        int flg = 0;
        int len = strlen(s)-1;
        for(int i = 0; i < len; i++){
            dp = ((dp<<1).set(0))&b[id(s[i])];
            if(dp[n-1]) printf("%d\n", i-n+2), flg = 1;
        }
        if(flg == 0) puts("NULL");
        scanf(" ");
    }
    return 0;
}
