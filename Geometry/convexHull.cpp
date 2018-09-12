#include <cstdio>
#include <algorithm>
#include "2DCommon.h"
int ConverHull(Point* p, int n, Point* ch)
{
    sort(p, p+n);
    int m = 0;
    for(int i = 0; i < n; i++){
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0)m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--){
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0)m--;
        ch[m++] = p[i];
    }
    if(n > 1)m--;
    return m;
}
