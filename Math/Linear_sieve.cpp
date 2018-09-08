//d[i]为i的最小质因子的次幂
const int MAX = 1e6+10;
int pnum,p[MAX],mob[MAX],noprime[MAX],facnum[MAX],d[MAX],phi[MAX];
void get_all()
{
    pnum = 0;
    phi[1] = 1;
    mob[1] = 1;
    facnum[1] = 1;
    for(int i = 2; i < MAX; i++)
    {
        if(!noprime[i])
        {
            phi[i] = i - 1;
            mob[i] = -1;
            p[pnum ++] = i;
            facnum[i] = 2;
            d[i] = 1;
        }
        for(int j = 0; j < pnum && i * p[j] < MAX; j++)
        {
            noprime[i * p[j]] = true;
            if(i % p[j] == 0)
            {
                phi[i * p[j]] = phi[i] * p[j];
                mob[i * p[j]] = 0;
                facnum[i * p[j]] = facnum[i] / (d[i] + 1) * (d[i] + 2);
                d[i * p[j]] = d[i] + 1;
                break;
            }
            phi[i * p[j]] = phi[i] * (p[j] - 1);
            mob[i * p[j]] = -mob[i];
            facnum[i * p[j]] = facnum[i] * 2;
            d[i * p[j]] = 1;
        }
    }
}
