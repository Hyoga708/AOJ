#include <bits/stdc++.h>
using namespace std;
int cnt[10][10];
int sx[]={-1,0,0,0,1},mx[]={-1,-1,-1,0,0,0,1,1,1},lx[]={-2,-1,-1,-1,0,0,0,0,0,1,1,1,2};
int sy[]={0,1,0,-1,0},my[]={1,0,-1,1,0,-1,1,0,-1},ly[]={0,1,0,-1,2,1,0,-1,-2,1,0,-1,0};
bool isInside(int y,int x){
	if(y<0||10<=y)	return false;
	if(x<0||10<=x)	return false;
	return true;
}
int main(){
	memset(cnt,0,sizeof(cnt));
	int x,y,s;
	while(scanf("%d,%d,%d",&x,&y,&s)!=EOF){
		switch(s){
			case 1:
				for(int i=0;i<5;i++){
					if(isInside(y+sy[i],x+sx[i]))	cnt[y+sy[i]][x+sx[i]]++;
				}
				break;
			case 2:
				for(int i=0;i<9;i++){
					if(isInside(y+my[i],x+mx[i]))	cnt[y+my[i]][x+mx[i]]++;
				}
				break;
			case 3:
				for(int i=0;i<13;i++){
					if(isInside(y+ly[i],x+lx[i]))	cnt[y+ly[i]][x+lx[i]]++;
				}
				break;
			case -1:
				goto end;
		}
	}
	end:;
	int big=0,blank=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(cnt[i][j]==0)	blank++;
			big=max(big,cnt[i][j]);
		}
	}
	cout<<blank<<endl;
	cout<<big<<endl;
	return 0;
}
