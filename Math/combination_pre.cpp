///简单递推
int c[maxn][maxn];
void init(){
    memset(c,0,sizeof(c));
    c[0][0] = c[1][0] = c[1][1] = 1;
    for(int i = 2; i < maxn; i++){
        c[i][0] = 1;
        for(int j = 1; j <= i; j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
    }
}

///预处理阶乘+逆元 
const int maxn = 1e6+10;
ll fac[maxn], iv[maxn];
void extgcd(ll aa,ll bb,ll& dd,ll& xx,ll& yy){
    if(!bb){
        dd = aa;
        xx = 1;
        yy = 0;
    }else{
        extgcd(bb, aa%bb, dd, yy, xx);
        yy -= xx*(aa/bb);
    }
}
ll inv(ll aa,ll mm){
    ll dd, xx, yy;
    extgcd(aa, mm, dd, xx, yy);
    return dd==1?(xx+mm)%mm:-1;
}
void init(){
    fac[0] = 1;
    iv[0] = inv(fac[0], mod);
    for(int i = 1; i < maxn; i++){
        fac[i] = (i*fac[i-1])%mod;
        iv[i] = inv(fac[i], mod);
    }
}
ll comb(int x, int y){
    if(x < y) swap(x,y);
    ll res = (fac[x]*iv[x-y])%mod;
    res = (res*iv[y])%mod;
    return res;
}
