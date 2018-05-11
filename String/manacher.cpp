#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e6+10;
char s[maxn];//原串
char t[maxn];//新串
int ma[maxn];
int n;//串长
int manacher()
{
    t[0] = '$', t[1] = '#';
    n = strlen(s);
    for(int i = 0; i < n; i++)t[i*2+2] = s[i], t[i*2+3] = '#';
    int mx = -1, ctr = -1, ret = 1;
    for(int i = 1; i < 2*n+2; i++){
        if(mx > i)ma[i] = min(ma[2*ctr-i], mx-i);
        else ma[i] = 1;
        while(t[i-ma[i]] == t[i+ma[i]])ma[i]++;
        if(i+ma[i]-1 > mx){
            mx = i+ma[i]-1;
            ctr = i;
        }
        ret = max(ret, ma[i]-1);
    }
    return ret;
}
