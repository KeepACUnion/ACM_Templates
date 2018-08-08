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

const int maxn = 2e6+10;
LL fac[maxn], iv[maxn];
void extgcd(LL aa,LL bb,LL& dd,LL& xx,LL& yy){
    if(!bb){
        dd = aa;
        xx = 1;
        yy = 0;
    }else{
        extgcd(bb, aa%bb, dd, yy, xx);
        yy -= xx*(aa/bb);
    }
}
LL inv(LL aa,LL mm){
    LL dd, xx, yy;
    extgcd(aa, mm, dd, xx, yy);
    return dd==1?(xx+mm)%mm:-1;
}
void init(){
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = (i*fac[i-1])%mod;
    iv[maxn-1] = inv(fac[maxn-1], mod);
    for(int i = maxn-2; i >= 0; i--) iv[i] = iv[i+1]*(i+1)%mod;
}
LL comb(int y, int x){
    if(x < y) swap(x,y);
    LL res = (fac[x]*iv[x-y])%mod;
    res = (res*iv[y])%mod;
    return res;
}
