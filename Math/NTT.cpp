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
void ntt(ll x[], int len, int on = 1){
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

/*
素数  rr  kk  gg
3   1   1   2
5   1   2   2
17  1   4   3
97  3   5   5
193 3   6   5
257 1   8   3
7681    15  9   17
12289   3   12  11
40961   5   13  3
65537   1   16  3
786433  3   18  10
5767169 11  19  3
7340033 7   20  3
23068673    11  21  3
104857601   25  22  3
167772161   5   25  3
469762049   7   26  3
1004535809  479 21  3
2013265921  15  27  31
2281701377  17  27  3
3221225473  3   30  5
75161927681 35  31  3
77309411329 9   33  7
206158430209    3   36  22
2061584302081   15  37  7
2748779069441   5   39  3
6597069766657   3   41  5
39582418599937  9   42  5
79164837199873  9   43  5
263882790666241 15  44  7
1231453023109121    35  45  3
1337006139375617    19  46  3
3799912185593857    27  47  5
4222124650659841    15  48  19
7881299347898369    7   50  6
31525197391593473   7   52  3
180143985094819841  5   55  6
1945555039024054273 27  56  5
4179340454199820289 29  57  3
*/
