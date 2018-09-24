#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;
const int sigma = 26;//字符集大小
const int maxn = 1e6+10;
bitset<maxn> bs[sigma], ans;
char s[sigma], t[maxn];
int n;//匹配串长度
void init()
{
    for(int i = 0; i < sigma; i++)bs[i].reset();
    for(int i = 0; i < n; i++){
        scanf("%s", s);//第i个位置可以匹配的字符集
        int l = strlen(s);
        for(int j = 0; j < l; j++)bs[s[j]-'a'].set(i);
    }
}
bool match()
{
    scanf("%s", t);
    int l = strlen(t);
    bool flg = 0;
    for(int i = 0; i < l; i++){
        ans <<= 1; ans.set(0);
        ans &= bs[t[i]-'a'];
        if(ans[n-1])flg = 1;
    }
    return flg;
}
