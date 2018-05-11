#include <cstring>
const int maxn = 1e6+10;
char s[maxn];//模式串
char t[maxn];//匹配串
int nxt[maxn];
int n, m;
void get_next()
{
    int k = -1;
    n = strlen(s);
    nxt[0] = -1;
    for(int i = 1; i < n; i++){
        while(k >= 0 && s[i] != s[k+1])k = nxt[k];
        if(s[i] == s[k+1])k++;
        nxt[i] = k;
    }
    //int cyc = n-1-nxt[n-1];
    //cyc = n%cyc?1:cyc;
}

bool match()
{
    int k = -1;
    m = strlen(t);
    for(int i = 0; i < n; i++){
        while(k >= 0 && t[i] != s[k+1])k = nxt[k];
        if(t[i] == s[k+1])k++;
        if(k == n-1)return 1;
    }
    return 0;
}
