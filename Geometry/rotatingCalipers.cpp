#include <cstdio>
#include <algorithm>
#include "2DCommon.h"
using namespace std;
double Dis(Point a, Point b){return Length(a-b);}
double Diameter(Point* p, int n)
{
    p[n] = p[0];
    double ret = 0;
    for(int i = 0, j = 1; i < n; i++){
        while(Area(p[i], p[i+1], p[j+1]) > Area(p[i], p[i+1], p[j]))j = (j+1)%n;
        ret = max(ret, Dis(p[i], p[j]));
        ret = max(ret, Dis(p[i+1], p[j]));
    }
    return ret;
}
double MaximumTriangle(Point *p, int n)
{
    if(n <= 2)return 0;
    p[n] = p[0];
    double ret = 0;
    for(int i = 0, u = 1, v = 2; i < n; i++){
        while(Area(p[i], p[u], p[(v+1)%n]) > Area(p[i], p[u], p[v]))v = (v+1)%n;
        while(Area(p[i], p[(u+1)%n], p[v]) > Area(p[i], p[u], p[v]))u = (u+1)%n;
        ret = max(ret, Area(p[i], p[u], p[v]));
    }
    return ret;
}
