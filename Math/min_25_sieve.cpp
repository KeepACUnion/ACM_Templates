做模版的时候把https://blog.csdn.net/dofypxy/article/details/80918865的几个公式加进去

const LL mod = 1e9+7;
const int maxn = 1e6+10;
LL p[maxn], pnum, nop[maxn];
void prime_sieve(){
    for(int i = 2; i < maxn; i++){
        if(!nop[i]) p[++pnum] = i;
        for(int j = 1; p[j]*i < maxn; j++){
            nop[p[j]*i] = 1;
            if(i%p[j] == 0) break;
        }
    }
}
LL qpow(LL x, LL k){
    LL res = 1;
    while(k > 0){
        if(k&1) res = res*x%mod;
        x = x*x%mod;
        k >>= 1;
    }
    return res;
}
LL g[2][maxn], h[2][maxn], nn, n, iv2;
inline LL get(LL func[2][maxn], LL idx){
    if(idx <= nn) return func[0][idx];
    return func[1][n/idx];
}
inline LL ff1(LL x){ return x;}
inline LL ff2(LL x){ return 1;}
inline LL sum1(LL x){ x %= mod; return x*(x+1)%mod*iv2%mod;}
inline LL sum2(LL x){ return x%mod;}
inline void _add(LL& a, LL b){a = (a+b)>=mod?a+b-mod:a+b;}
inline void _sub(LL& a, LL b){a = (a-b)<0?a-b+mod:a-b;}
void calc(){
    for(int i = 1; i <= nn; i++){
        g[0][i] = sum1(i)-1, g[1][i] = sum1(n/i)-1;
        h[0][i] = sum2(i)-1, h[1][i] = sum2(n/i)-1;
    }
    for(int j = 1; j <= pnum; j++){
        for(int i = 1; i <= nn && n >= 1LL*i*p[j]*p[j]; i++){
            _sub(g[1][i], ff1(p[j])*(get(g, n/i/p[j])-get(g,p[j-1]))%mod);
            _sub(h[1][i], ff2(p[j])*(get(h, n/i/p[j])-get(h,p[j-1]))%mod);
        }
        for(int i = nn; i >= 1 && i >= 1LL*p[j]*p[j]; i--){
            _sub(g[0][i], ff1(p[j])*(get(g, i/p[j])-get(g,p[j-1]))%mod);
            _sub(h[0][i], ff2(p[j])*(get(h, i/p[j])-get(h,p[j-1]))%mod);
        }
    }
    
    for(int i = 1; i <= nn; i++){
        _sub(g[0][i], h[0][i]); _add(g[0][i],2);
        _sub(g[1][i], h[1][i]); _add(g[1][i],2);
        if(i < 2) _add(g[0][i], -2);
    }
}
inline LL f(LL prime, LL k){ return prime ^ k;}
LL ask(LL a, int b){
    if(a < p[b]) return 0;
    LL ret = get(g,a)-get(g,p[b]-1);
    if(n < 1LL*p[b]*p[b]) return ret;
    for(int j = b; j<=pnum && 1LL*p[j]*p[j]<=a; j++){
        for(LL pp = p[j], k=1; p[j]*pp <= a; k++, pp *= p[j]){
            _add(ret, ask(a/pp,j+1)*f(p[j],k)%mod);
            _add(ret, f(p[j],k+1));
        }
    }
    return ret;
}

int main(){
    prime_sieve();
    cin >> n;
    nn = (LL)sqrt(n); 
    iv2 = (mod+1)/2;
    calc();
    cout << (ask(n, 1)+1+mod)%mod << endl;
    return 0;
}
