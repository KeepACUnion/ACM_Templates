#include <cstdio>
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
