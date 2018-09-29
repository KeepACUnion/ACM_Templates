/******
 * NTT Algorithm
 * Time Complexity: O(nlog n)
 * available data range rely on the value of g and modn
 * default range:
 * * 0 <= ai < 1004535809 (a number slightly bigger than 1e9)
 * * n<= 2^21
 ******/
const int mod = 119 << 23 | 1;
const int G = 3;
int wn[20];
void getwn(){ //  千万不要忘记
    for (int i = 0; i < 20; i++) wn[i] = Pow(G, (mod - 1) / (1 << i), mod);
}
void change(int y[], int len){
    for (int i = 1, j = len / 2; i < len - 1; i++){
        if (i < j) swap(y[i], y[j]);
        int k = len / 2;
        while (j >= k) j -= k, k /= 2;
        if (j < k) j += k;
    }
}
void ntt(int y[], int len, int on){
    change(y, len);
    for (int h = 2, id = 1; h <= len; h <<= 1, id++){
        for (int j = 0; j < len; j += h){
            int w = 1;
            for (int k = j; k < j + h / 2; k++){
                int u = y[k] % mod;
                int t = 1LL * w * (y[k + h / 2] % mod) % mod;
                y[k] = (u + t) % mod, y[k + h / 2] = ((u - t) % mod + mod) % mod;
                w = 1LL * w * wn[id] % mod;
            }
        }
    }
    if (on == -1){
        //  原本的除法要用逆元
        int inv = Pow(len, mod - 2, mod);
        for (int i = 1; i < len / 2; i++) swap(y[i], y[len - i]);
        for (int i = 0; i < len; i++) y[i] = 1LL * y[i] * inv % mod;
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
