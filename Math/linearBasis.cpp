typedef long long ll;
const int maxl = 64;
ll b[maxl];
void insert(ll x)
{
    for(int i = maxl-1; i >= 0; i--){
        if((x>>i)&1){
            if(b[i])x ^= b[i];
            else{
                b[i] = x;
                for(int j = i-1; j >= 0; j--)if(b[j] && ((b[i]>>j)&1))b[i] ^= b[j];
                for(int j = i+1; j < maxl; j++)if((b[j]>>i)&1)b[j] ^= b[i];
                break;
            }
        } 
    }
}

ll get_max()
{
    ll ret = 0;
    for(int i = 0; i < maxl; i++)ret ^= b[i];
    return ret;
}
