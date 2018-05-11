#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
const int sigma = 26;
char s[maxn];
struct Node
{
    int idx, state, nxt[maxn][sigma], len[maxn], sz[maxn], fail[maxn];
    void init()
    {
        idx = 1, state = 0;
        fail[0] = fail[1] = 1; len[1] = -1;
        memset(nxt[0], 0, sizeof(nxt[0]));
        memset(nxt[1], 0, sizeof(nxt[1]));
    }
    int newNode()
    {
        int p = ++idx;
        memset(nxt[p], 0, sizeof(nxt[p]));
        len[p] = sz[p]  = fail[p] = 0;
        return p;
    }
    void insert(int x, int pos)
    {
        int rt = state;
        while(s[pos-len[rt]-1] != s[pos])rt = fail[rt];
        if(!nxt[rt][x]){
            int v = newNode(), q = fail[rt]; 
            len[v] = len[rt]+2;
            while(s[pos-len[q]-1] != s[pos])q = fail[q];
            fail[v] = nxt[q][x];
            nxt[rt][x] = v;
        }
        state = nxt[rt][x], sz[state]++;
    }
    ll count()
    {
        ll ans = 0;
        for(int i = idx; i > 0; i--){
            sz[fail[i]] += sz[i];
            ans = max(ans, 1LL*len[i]*sz[i]);
        }
        return ans;
    }
}PAM;
