const int BITNUM = 63;
ll b[BITNUM];
void Insert(ll x){
    for(int i = BITNUM-1; i >= 0; i--){
        if(!(x>>i&1)) continue;
        if(b[i]) x ^= b[i];
        else{
            b[i] = x;
            for(int j = i-1; j >= 0; j--)
                if(b[j] && (b[i]>>j&1)) b[i] ^= b[j];
            for(int j = i+1; j < BITNUM; j++)
                if(b[j]>>i&1) b[j] ^= b[i];
            break;
        }
    }
}
