#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int Mo = int(1e9) + 7;
const LL Inv2 = 500000004;
const LL Inv6 = 166666668;
/// f(n)=sigma{[0,n], (a*i+b)/c} 
/// g(n)=sigma{[0,n], i*((a*i+b)/c)}
/// h(n)=sigma{[0,n], ((a*i+b)/c)^2}
struct Node{
	int a,b,c;

	Node(void){}
	Node(int a,int b,int c) : a(a),b(b),c(c){}
};
LL sqr(LL a){
	a %= Mo;
	return a * a % Mo;
}
LL Calc(int sig,LL R){
	R %= Mo;
	if (sig == 0) return (R + 1) % Mo;
	if (sig == 1) return R * (R + 1) % Mo * Inv2 % Mo;
	if (sig == 2) return R * (R + 1) % Mo * (2 * R % Mo + 1) % Mo * Inv6 % Mo;
}
Node Solve(LL R,LL a,LL b,LL c){
	R %= Mo;
	if (!R) return Node((b / c) % Mo,sqr(b / c),0);
	if (!a)
	{
		LL tmp = (b / c) % Mo;
		return Node(tmp * Calc(0,R) % Mo,tmp * tmp % Mo * Calc(0,R) % Mo,tmp * Calc(1,R) % Mo);
	}
	LL MAX = (a * R + b) / c - 1;
	if ((a / c) || (b / c))
	{
		Node cr;
		Node tmp = Solve(R,a % c,b % c,c);
		cr.a = (((a / c) % Mo * Calc(1,R) % Mo + (b / c) % Mo * Calc(0,R) % Mo) % Mo + tmp.a) % Mo;
		cr.b = (sql(a / c) * Calc(2,R) % Mo + sqr(b / c) * Calc(0,R) % Mo) % Mo;
		cr.b = ((cr.b + tmp.b) % Mo + (2 * ((a / c) % Mo) % Mo * ((b / c) % Mo) % Mo * Calc(1,R))) % Mo;
		cr.b = ((cr.b + 2 * ((a / c) % Mo) % Mo * tmp.c % Mo) % Mo + 2 * ((b / c) % Mo) % Mo * tmp.a % Mo) % Mo;
		cr.c = (((a / c) % Mo * Calc(2,R) % Mo + ((b / c) % Mo) * Calc(1,R) % Mo) % Mo + tmp.c) % Mo;
		return cr;
	}
	Node cr;
	Node tmp = Solve(MAX,c,c - b - 1,a);
	MAX %= Mo;
	cr.a = ((R) * (MAX + 1) % Mo - tmp.a + Mo) % Mo;
	cr.b = (2 * (R % Mo * Calc(1,MAX) % Mo - tmp.c + Mo) % Mo + cr.a) % Mo;
	cr.c = Inv2 * (((R % Mo * (R + 1) % Mo * (MAX + 1) % Mo - tmp.b + Mo) % Mo - tmp.a + Mo) % Mo) % Mo;
	return cr;
}
int main(){
	freopen("task.in","r",stdin),freopen("task.out","w",stdout);
	int A,B,C,L,R;
	scanf("%d%d%d%d%d", &A, &B, &C, &L, &R);
	printf("%d\n", (Solve(R,A,C,B).c - Solve(L - 1,A,C,B).c + Mo) % Mo);
	return 0;
}

/******************只有f的******/
LL f(LL a, LL b, LL c, LL n){
	if(!a) return (b/c)*(n+1);
	if(a>=c||b>=c) return f(a%c,b%c,c,n)+(a/c)*n*(n+1)/2+(b/c)*(n+1);
	LL m=(a*n+b)/c, v=f(c,c-b-1,a,m-1);
	return n*m-v;
}