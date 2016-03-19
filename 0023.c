#include <stdio.h>
#include <math.h>
const double eps=1e-9;
struct Circle{
	double x,y,r;
};
typedef struct Circle Circle;
Circle input(){
	Circle ret;
	scanf("%lf %lf %lf",&ret.x,&ret.y,&ret.r);
	return ret;
}
double distance(Circle a,Circle b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
	int n;	scanf("%d",&n);
	while(n--){
		Circle a=input(),b=input();
		double dist=distance(a,b);
		if(a.r-dist-b.r>eps)	printf("2\n");
		else if(b.r-dist-a.r>eps)	printf("-2\n");
		else if(a.r+b.r-dist>-eps)	printf("1\n");
		else 	printf("0\n");
	}
	return 0;
}
			
