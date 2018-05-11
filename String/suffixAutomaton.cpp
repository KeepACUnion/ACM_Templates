#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
const int maxn = 1e6+10;
const int sigma = 26;
int ans[maxn];
char s[maxn];
struct Trie
{
    int nxt[maxn][sigma], par[maxn], len[maxn], right[maxn];
    vector<int> son[maxn];
    int lst, idx;
    int newNode()
    {
        int u = ++idx;
        memset(nxt[u], 0, sizeof(nxt[u]));
        par[u] = len[u] = right[u] = 0;
        return u;
    }
    void init()
    {
        idx = 0;
        lst = newNode();
    }
    void extend(int c)
    {
        int rt = lst, np = newNode();
        right[np] = 1;
        len[np] = len[rt]+1;
        for(; rt && !nxt[rt][c]; rt = par[rt])nxt[rt][c] = np;
        if(!rt)par[np] = 1;
        else{
            int q = nxt[rt][c];
            if(len[q] == len[rt]+1)par[np] = q;
            else{
                int nq = ++idx;
                right[nq] = 0;
                par[nq] = par[q];
                len[nq] = len[rt]+1;
                memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
                par[np] = par[q] = nq;
                for(; rt && nxt[rt][c] == q; rt = par[rt])nxt[rt][c] = nq;
            }
        }
        lst = np;
    }
    void dfs(int u)
    {
        for(auto v : son[u]){
            dfs(v);
            right[u] += right[v];
        }
    }
    void solve()
    {
        for(int i = 2; i <= idx; i++)son[par[i]].pb(i);
        dfs(1);
        for(int i = 2; i <= idx; i++)ans[len[i]] = max(ans[len[i]], right[i]);
    }
}SAM;
