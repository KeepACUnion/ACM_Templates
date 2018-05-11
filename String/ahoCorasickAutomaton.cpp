#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e6+10;
const int sigma = 26;
char s[maxn];
struct Node
{
    int nxt[maxn][sigma], fail[maxn], last[maxn], idx;
    int newNode()
    {
        int x = ++idx;
        memset(nxt[x], -1, sizeof(nxt[x]));
        fail[x] = last[x] = 0;
        return x;
    }
    void init()
    {
        idx = 0;
        memset(nxt[0], -1, sizeof(nxt[0]));
        fail[0] = last[0] = 0;
    }
    void insert()
    {
        int rt = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int u = s[i]-'a';
            if(nxt[rt][u] == -1)nxt[rt][u] = newNode();
            rt = nxt[rt][u];
        }
        last[rt]++;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        fail[rt] = rt;
        for(int i = 0; i < sigma; i++){
            int &u = nxt[rt][i];
            if(u == -1)u = rt;
            else{
                fail[u] = rt;
                q.push(u);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < sigma; i++){
                int &v = nxt[u][i];
                int w = fail[u];
                if(v == -1)v = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    q.push(v);
                }
            }
        }
    }
    int get_ans()
    {
        int rt = 0, n = strlen(s), ret = 0;
        for(int i = 0; i < n; i++){
            int u = s[i]-'a';
            rt = nxt[rt][u];
            int tmp = rt;
            while(tmp){
                if(last[tmp])ret += last[tmp], last[tmp] = 0;
                tmp = fail[tmp];
            }
        }
        return ret;
    }
}ACAM;
