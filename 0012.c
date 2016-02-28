#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct Point{
	double x,y;
};
typedef struct Point Point;
double calc(Point a,Point b,Point c){
	Point m=(Point){b.x-a.x,b.y-a.y};
	Point n=(Point){c.x-a.x,c.y-a.y};
	double S=fabs(m.x*n.y-m.y*n.x);
	return S/2.0;
}
int main(){
	Point a,b,c,p;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
		&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&p.x,&p.y)!=EOF){
		double S=calc(a,b,c);
		double s1=calc(p,a,b),s2=calc(p,b,c),s3=calc(p,c,a);
		if(s1==0.0||s2==0.0||s3==0.0){
			printf("NO\n");
			continue;
		}
		if(S>=s1+s2+s3)	printf("YES\n");
		else 	printf("NO\n");
	}
	return 0;
}
