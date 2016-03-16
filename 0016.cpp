#include <bits/stdc++.h>
using namespace std;
int flr(double x){
	if(x<0)	return ceil(x);
	else 	return floor(x);
}
int main(){
	double x=0,y=0;
	int arg=90;
	while(true){
		int d,a;	scanf("%d,%d",&d,&a);
		if(d==0&&a==0)	break;
		double args=(arg)/180.0*M_PI;
		x+=d*cos(args);	y+=d*sin(args);
		arg-=a;
	}
	printf("%d\n",flr(x));
	printf("%d\n",flr(y));
	return 0;
}
