const int maxnode = 1e5+10;
const int maxn = 1e3+10;
struct DLX
{
    int n, m, size;
    int U[maxnode], D[maxnode], L[maxnode], R[maxnode], col[maxnode], row[maxnode];
    int H[maxn], S[maxn];
    int ansd, ans[maxn];
    void init(int _n, int _m)
    {
        n = _n, m = _m;
        for(int i = 0; i <= m; i++)
            S[i] = 0, U[i] = D[i] = i, L[i] = i - 1, R[i] = i + 1;
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
        for(int i = U[c]; i != c; i = U[i])
            for(int j = L[i]; j != i; j = L[j])
                ++S[col[U[D[j]] = D[U[j]] = j]];
        L[R[c]] = R[L[c]] = c;
    }
    bool dancing(int dep)
    {
        if(R[0] == 0){
            ansd = dep;
            return true;
        }
        int c = R[0];
        for(int i = R[0]; i != 0; i = R[i]){
            if(S[i] < S[c])c = i;
        }
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
