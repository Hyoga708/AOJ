#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int grd[1010][1010];
int main(){
	while(true){
	int h,w,n;	cin>>h>>w>>n;
	if(h==0)	return 0;
	memset(dp,0,sizeof(dp));	memset(grd,0,sizeof(grd));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)	cin>>grd[i][j];
	}
	dp[0][0]=n-1;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(j+1<w){
				if(grd[i][j]==1)	dp[i][j+1]+=(dp[i][j]+1)/2;
				else 	dp[i][j+1]+=dp[i][j]/2;
			}
			if(i+1<h){
				if(grd[i][j]==1)	dp[i+1][j]+=dp[i][j]/2;
				else 	dp[i+1][j]+=(dp[i][j]+1)/2;
			}
			dp[i][j]%=2;
		}
	}
	int x=0,y=0;
	while(x<w&&y<h){
		if((grd[y][x]^dp[y][x])==1)	x++;
		else 	y++;
	}
	cout<<y+1<<" "<<x+1<<endl;
	}
}
