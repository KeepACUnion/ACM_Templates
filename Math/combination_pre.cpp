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

///O(nlogn)预处理阶乘+逆元 
const int maxc = 2e6+10;
LL fac[maxc], iv[maxc];
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
    for(int i = 1; i < maxc; i++) fac[i] = (i*fac[i-1])%mod;
    iv[maxc-1] = inv(fac[maxc-1], mod);
    for(int i = maxc-2; i >= 0; i--) iv[i] = iv[i+1]*(i+1)%mod;
}
LL comb(int y, int x){
    if(x < y) swap(x,y);
    return fac[x]*iv[x-y]%mod*iv[y]%mod;
}


//O(n)预处理,mod必须是质数
const int maxc = 1e6+10;
int FAC[maxc], IVF[maxc], IV[maxc];
void init(){
    IV[1] = FAC[0] = FAC[1] = IVF[1] = 1;
    for(int i = 2; i < maxc; i++){
        FAC[i] = 1LL*FAC[i-1]*i%mod;
        IV[i] = 1LL*(mod-mod/i)*IV[mod%i]%mod;
        IVF[i] = 1LL*IVF[i-1]*IV[i]%mod;
    }
}
LL comb(int x, int y){
    if(x < y) swap(x,y);
    return 1LL*FAC[x]*IVF[x-y]%mod*IVF[y]%mod;
}
