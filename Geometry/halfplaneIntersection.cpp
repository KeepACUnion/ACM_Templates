#include <cstdio>
#include <algorithm>
#include "2DCommon.h"
struct Line
{
    Point P;
    Vector v;
    double ang;
    Line(){}
    Line(Point P, Vector v):P(P), v(v){}
    bool operator < (const Line& L)const{return ang < L.ang;}
};
bool OnLeft(Line L, Point p)
{
    return Cross(L.v, p-L.P);
}
Point GetIntersection(Line a, Line b)
{
    Vector u = a.P-b.P;
    double t = Cross(b.v, u)/Cross(a.v, b.v);
    return a.P+a.v*t;
}
int HalfplaneIntersection(Line* L, int n, Point* poly)
{
    sort(L, L+n);
    int first, last;
    Point *p = new Point[n];
    Line *q = new Line[n];
    q[first=last=0] = L[0];
    for(int i = 1; i < n; i++){
        while(first < last && !OnLeft(L[i], p[last-1]))last--;
        while(first < last && !OnLeft(L[i], p[first]))first++;
        q[last++] = L[i];
        if(fabs(Cross(q[last].v, q[last-1].v)) < eps){
            last--;
            if(OnLeft(q[last], L[i].P))q[last] = L[i];
        }
        if(first < last)p[last-1] = GetIntersection(q[last-1], q[last]);
    }
    while(first < last && !OnLeft(q[first], p[last-1]))last--;
    if(last-first <= 1)return 0;
    p[last] = GetIntersection(q[last], q[first]);
    int m = 0;
    for(int i = first; i <= last; i++)poly[m++] = p[i];
    return m;
}
