#include <cstring>
const int maxn = 13;
int fac[maxn];
int s[maxn];
bool tmp[maxn];
int n;
void init()
{
    fac[0] = 1;
    for(int i = 1; i < maxn; i++)fac[i] = fac[i-1]*i;
}
int cantor()  
{  
    int num=0;  
    for(int i = 0; i < n-1; i++)  
    {  
        int tmp = 0;  
        for(int j = i+1; j<n; j++)  
            if(s[j] < s[i])tmp++;  
        num += fac[n-i-1]*tmp;  
    }  
    return num;
}
void _cantor(int x)  
{  
    memset(tmp, 0, sizeof(tmp));
    for(int i=n-1;i>=0;i--)  
    {  
        int k = x/fac[i]; x %= fac[i];  
        int j = 1;  
        for(int sum = 0; sum < k || tmp[j]; j++)  
            if(!tmp[j])sum++;
        s[n-1-i]=j;
        tmp[j]=1;  
    }
}
