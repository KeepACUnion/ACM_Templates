int cantor(int *s,int n)  
{  
    int num=0;  
    for(int i=0;i<n-1;i++)  
    {  
        int tmp=0;  
        for(int j=i+1;j<n;j++)  
            if(s[j]<s[i])tmp++;  
        num+=fac[n-i-1]*tmp;  
    }  
    return num;  
}
void _cantor(int *s,int n,int x)  
{  
    bool tmp[n+1];  
    clr(tmp,0);  
    for(int i=n-1;i>=0;i--)  
    {  
        int k=x/fac[i];x%=fac[i];  
        int j=1;  
        for(int sum=0;sum<k||tmp[j];j++)  
            if(!tmp[j])sum++;  
        s[n-1-i]=j;  
        tmp[j]=1;  
    }  
}  