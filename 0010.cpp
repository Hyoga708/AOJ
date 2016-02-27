#include <bits/stdc++.h>
using namespace std;
class Point{
	public:
	double x,y;
	void input(){
		cin>>x>>y;
	}
};
double dist(Point a,Point b){
	return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));
}
class Line{
	public:
	double a,b,c;//ax+by=c
	Line(Point s,Point t){
		//x=(x1+x2)/2 , y=(y1+y2)/2を通り、
		//傾きa=-(x1-x2)/(y1-y2)の直線
		//(y1-y2)(y-(y1+y2)/2) = -(x1-x2)(x-(x1+x2)/2)
		//(x1-x2)x + (y1-y2)y = (x1^2-x2^2)/2 + (y1^2-y2^2)/2
		a=s.x-t.x;	b=s.y-t.y;
		c=((s.x+t.x)*(s.x-t.x)+(s.y+t.y)*(s.y-t.y))/2.0;
	}
	void multi(double x){
		a*=x;	b*=x;	c*=x;
	}
};
double searchx(Line s,Line t){
	double tmp=s.b;
	s.multi(t.b);	t.multi(tmp);
	return (s.c-t.c)/(s.a-t.a);
}
double searchy(Line s,Line t){
	double tmp=s.a;
	s.multi(t.a);	t.multi(tmp);
	return (s.c-t.c)/(s.b-t.b);
}
int main(){
	int n;	cin>>n;
	while(n--){
		Point a,b,c;
		a.input();	b.input();	c.input();
		Line l(a,b),m(b,c);
		Point center;
		center.x=searchx(l,m);	center.y=searchy(l,m);
		double dis=dist(center,a);
		printf("%.3lf %.3lf %.3lf\n",center.x,center.y,dis);
	}
	return 0;
}
