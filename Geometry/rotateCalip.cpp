/*旋转卡壳求凸包中最远点对*/
double Dis(Point a, Point b){return Length(a-b);}
double Area(Point a, Point b, Point c){return Cross(b-a,c-a);}
double rot_calip(Point* p, int n){
    double res = 0;
    p[n] = p[0];
    for(int i = 0, j = 1; i < n; i++){
        while(Area(p[i],p[i+1],p[j+1]) > Area(p[i],p[i+1],p[j])) j=(j+1)%n;
        res = max(res, Dis(p[i], p[j]));
        res = max(res, Dis(p[i+1], p[j]));
    }
    return res;
}
