#include <stdio.h>
const double eps=1e-9;

struct Point{
	double x,y;
};
typedef struct Point Point;
struct Line{
	double a,b,c;//ax+by+c=0
};
typedef struct Line Line;

void input(Point *ret){
	scanf("%lf %lf",&ret->x,&ret->y);
}
Line make(Point a,Point b){
	//(ax-bx)(y-ay)=(ay-by)(x-ax)
	//(ay-by)x+(bx-ax)y+ay(ax-bx)+ax(by-ay)=0
	Line ret;
	ret.a=a.y-b.y;
	ret.b=b.x-a.x;
	ret.c=a.y*(a.x-b.x)+a.x*(b.y-a.y);
	return ret;
}

int main(){
	int n;	scanf("%d",&n);
	while(n--){
		Point a,b,c,d;
		input(&a);	input(&b);	input(&c);	input(&d);
		Line l1=make(a,b);
		Line l2=make(c,d);
		if(-eps<l1.b&&l1.b<eps){
			if(-eps<l2.b&&l2.b<eps)	printf("YES\n");
			else 	printf("NO\n");
		}
		else if(-eps<l2.b&&l2.b<eps)	printf("NO\n");
		else{
			double l1a=l1.a/l1.b;
			double l2a=l2.a/l2.b;
			if(-eps<l1a-l2a&&l1a-l2a<eps)	printf("YES\n");
			else 	printf("NO\n");
		}
	}
	return 0;
}
