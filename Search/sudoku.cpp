#include <cstdio>
#include <cstring>
const int maxn = 1e3+10;
const int maxnode = 5e5+10;
char s[100];
struct DLX
{
    int n, m, size;
    int U[maxnode], D[maxnode], L[maxnode], R[maxnode], col[maxnode], row[maxnode];
    int H[maxn], S[maxn];
    int ansd, ans[maxn];
    void init(int _n, int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0; i <= m; i++)S[i] = 0, U[i] = D[i] = i, L[i] = i - 1, R[i] = i + 1;
        L[0] = m, R[m] = 0;
        size = m;
        for(int i = 1; i <= n; i++)H[i] = -1;
    }
    void push(int r, int c)
    {
        ++S[col[++size] = c];
        row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else{
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }
    void del(int c)
    {
        L[R[c]] = L[c];
        R[L[c]] = R[c];
        for(int i = D[c]; i != c; i = D[i]){
            for(int j = R[i]; j != i; j = R[j]){
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[col[j]];
            }
        }
    }
    void reback(int c)
    {
        for(int i = U[c]; i != c; i = U[i]){
            for(int j = L[i]; j != i; j = L[j]){
                ++S[col[U[D[j]] = D[U[j]] = j]];
            }
        }
        L[R[c]] = R[L[c]] = c;
    }
    bool dancing(int dep)
    {
        if(R[0] == 0){
            for(int i = 0; i < dep; i++)s[(ans[i]-1)/9] = (ans[i]-1)%9+'1';
            for(int i = 0; i < 81; i++)printf("%c", s[i]);
            puts("");
            return true;
        }
        int c = R[0];
        for(int i = R[0]; i != 0; i = R[i])if(S[i] < S[c])c = i;
        del(c);
        for(int i = D[c]; i != c; i = D[i]){
            ans[dep] = row[i];
            for(int j = R[i]; j != i; j = R[j])del(col[j]);
            if(dancing(dep + 1))return true;
            for(int j = L[i]; j != i; j = L[j])reback(col[j]);
        }
        reback(c);
        return false;
    }
}dlx;
void place(int &r, int &c1, int &c2, int &c3, int &c4, int i, int j, int k)
{
    r = (i*9+j)*9+k;
    c1 = i*9+j+1;
    c2 = 9*9+i*9+k;
    c3 = 9*9*2+j*9+k;
    c4 = 9*9*3+((i/3)*3+(j/3))*9+k;
}
void solve()
{
    dlx.init(9*9*9, 9*9*4);
    int r, c1, c2, c3, c4;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 1; k <= 9; k++){
                if(s[i*9+j] == '.' || s[i*9+j]-'0' == k){
                    place(r, c1, c2, c3, c4, i, j, k);
                    dlx.push(r, c1);
                    dlx.push(r, c2);
                    dlx.push(r, c3);
                    dlx.push(r, c4);
                }
            }
        }
    }
    dlx.dancing(0);
}
