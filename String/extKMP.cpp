#include <algorithm>
using namespace std;
const int maxn = 2e6+10;
char s[maxn], t[maxn];
int nxt[maxn], ext[maxn];
void get_next()
{
    int k = 0, n = strlen(t);
    while(k+1 < n && t[k]==t[k+1])k++;
    nxt[1] = k;
    int pos = 1;
    for(int i = 2; i < n; i++){
        if(i+nxt[i-pos] < pos+nxt[pos])nxt[i] = nxt[i-pos];
        else{
            k = max(0, pos+nxt[pos]-i);
            while(i+k < n && t[k] == t[i+k])k++;
            nxt[i] = k;
            pos = i;
        }
    }
}
void exKMP()
{
    get_next();
    int k = 0, n = strlen(s);
    while(k < n && s[k] == t[k])k++;
    ext[0] = k;
    int pos = 0;
    for(int i = 1; i < n; i++){
        if(i+nxt[i-pos] < pos+ext[pos])ext[i] = nxt[i-pos];
        else{
            k = max(0, pos+ext[pos]-i);
            while(i+k < n && s[i+k] == t[k])k++;
            ext[i] = k;
            pos = i;
        }
    }
}

