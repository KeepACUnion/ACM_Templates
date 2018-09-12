#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-10;
int dcmp(double x){return x<-eps?-1:x>eps;}
struct Point
{
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}
    Point operator + (const Point &rhs)const{return Point(x+rhs.x, y+rhs.y);}
    Point operator - (const Point &rhs)const{return Point(x-rhs.x, y-rhs.y);}
    Point operator * (const double p)const{return Point(x*p, y*p);}
    Point operator / (const double p)const{return Point(x/p, y/p);}
    bool operator < (const Point &rhs)const{return x < rhs.x || (x == rhs.x && y < rhs.y);}
    bool operator == (const Point &rhs)const{return !dcmp(x-rhs.x) && !dcmp(y-rhs.y);}
};
typedef Point Vector;
double Dot(Vector A, Vector B){return A.x*B.x+A.y*B.y;}
double Cross(Vector A, Vector B){return A.x*B.y-A.y*B.x;}
double Length(Vector A){return sqrt(Dot(A, A));}
double Angle(Vector A, Vector B){return acos(Dot(A, B)/Length(A)/Length(B));}
double Area(Point A, Point B, Point C){return Cross(B-A, C-A);}
Vector Rotate(Vector A, double rad){return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));}
Vector Normal(Vector A)
{
    double L = Length(A);
    return Vector(-A.y/L, A.x/L);
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
    Vector u = P-Q;
    double t = Cross(w, u)/Cross(v, w);
    return P+v*t;
}//求两直线交点(需保证Cross(v, w) != 0)
double DistanceToLine(Point P, Point A, Point B)
{
    Vector v1 = B-A, v2 = P-A;
    return fabs(Cross(v1, v2))/Length(v1);
}//求点P到直线AB的距离
double DistanceToSegment(Point P, Point A, Point B)
{
    if(A == B)return Length(P-A);
    Vector v1 = B-A, v2 = P-A, v3 = P-B;
    if(dcmp(Dot(v1, v2)) < 0)return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0)return Length(v3);
    else return fabs(Cross(v1, v2))/Length(v1);
}//求点P到线段AB的距离
Point GetLineProjection(Point P, Point A, Point B)
{
    Vector v = B-A;
    return A+v*(Dot(v, P-A)/Dot(v, v));
}//求点P在直线AB上的投影
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1), 
        c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}//线段相交判定(不含端点)
bool OnSegment(Point p, Point a1, Point a2)
{
    return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}
double PolygonArea(Point*p, int n)
{
    double area = 0;
    for(int i = 1; i < n-1; i++)area += Cross(p[i]-p[0], p[i+1]-p[0]);
    return area/2;
}//多边形(凹凸皆可)有向面积，逆时针为正，
bool isPointInPolygon(Point p, int n, Point* poly)
{
    int wn = 0;
    for(int i = 0; i < n; i++){
        if(OnSegment(p, poly[i], poly[(i+1)%n]))return -1;//在边界上
        int k = dcmp(Cross(poly[(i+1)%n]-poly[i], p-poly[i]));
        int d1 = dcmp(poly[i].y-p.y);
        int d2 = dcmp(poly[(i+1)%n].y-p.y);
        if(k > 0 && d1 <= 0 && d2 > 0)wn++;
        if(k < 0 && d2 <= 0 && d1 > 0)wn--;
    }
    return wn;
}//判断点p是否在多边形内
