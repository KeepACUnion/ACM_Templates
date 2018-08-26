/******
 * NTT Algorithm
 * Time Complexity: O(nlog n)
 * available data range rely on the value of g and modn
 * default range:
 * * 0 <= ai < 1004535809 (a number slightly bigger than 1e9)
 * * n<= 2^21
 * prototype problem: HDU1402
 ******/
typedef long long ll;
const ll g = 3, modn = (479<<21)+1;
const int maxn = 1<<17;
ll a[maxn], b[maxn];
char s[maxn];
ll quickpow(ll base, ll n, const ll &P){
    ll ans = 1;
    while(n){
        if(n&1) ans = ans*base%P;
        base = base*base%P;
        n >>= 1;
    }
    return ans;
}
inline ll multi(ll x,ll y,ll P){
    ll tmp=(x*y-(ll)((long double)x/P*y+1.0e-8)*P);
    return tmp<0 ? tmp+P : tmp;
}
inline int nor(int x) { return x<0?x+modn:x<modn?x:x-modn; }
/// len: must be 2^k and not smaller than length of x
/// note that len of NTT must be equal to len of INTT
void ntt(ll x[], const int &len, const int &on){
    for(int i=1, j=len/2; i<len-1; i++) {
        if(i<j) swap(x[i], x[j]);
        int k = len/2;
        while(j>=k) {
            j -= k;
            k >>=1;
        }
        if(j<k) j += k;
    }
    for(int k=1; k<len; k<<=1) {
        // wm[pos] = quickpow(g, modn>>(pos+1), modn);
        ll wm = quickpow(g, modn/2/k, modn);
        for(int i=0; i<len; i+=2*k) {
            ll w = 1;
            for(int j=0; j<k; j++) {
                ll u = x[i+j];
                ll t = w*x[i+j+k]%modn;
                x[i+j] = nor(u+t);
                x[i+j+k] = nor(u-t);
                w = w*wm%modn;
            }
        }
    }
    if(on == -1) {
        reverse(x+1, x+len);
        long long inv = quickpow(len, modn-2, modn);
        for(int i=0; i<len; i++)
            x[i] = x[i]*inv%modn;
    }
}
/**
prime number:
  g   r   k             modn
  3   1  16  1<<16|1   = 65537
  3   7  26  7<<26|1   = 469762049
  3 119  23  119<<23|1 = 998244353
  3 479  21  479<<21|1 = 1004535809
 31  15  27  15<<27|1  = 2013265921
  3  17  27  17<<27|1  = 2281701377
  5  27  56  27<<56|1  = 1945555039024054273
  **/
