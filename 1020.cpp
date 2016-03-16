#include <bits/stdc++.h>
using namespace std;
int dp[20][3][3];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int main(){
	while(true){
		int n;	cin>>n;
		if(n==0)	return 0;
		char s,t,b;	cin>>s>>t>>b;
		int sx,sy,tx,ty,bx,by;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				int num=3*i+j;
				if(num==s-'A'){
					sy=i;	sx=j;
				}
				if(num==t-'A'){
					ty=i;	tx=j;
				}
				if(num==b-'A'){
					by=i;	bx=j;
				}
			}
		}
		for(int i=0;i<20;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					dp[i][j][k]=0;
		dp[0][sy][sx]=1;
		for(int i=0;i<n;i++){
			for(int y=0;y<3;y++){
				for(int x=0;x<3;x++){
					if(dp[i][y][x]==0)	continue;
					for(int l=0;l<4;l++){
						int ny=y+dy[l];
						int nx=x+dx[l];
						if(ny<0||3<=ny||nx<0||3<=nx){
							dp[i+1][y][x]+=dp[i][y][x];
						}
						else if(bx==nx&&by==ny){
							dp[i+1][y][x]+=dp[i][y][x];
						}
						else{
							dp[i+1][ny][nx]+=dp[i][y][x];
						}
					}
				}
			}
		}
		printf("%.15lf\n",(double)dp[n][ty][tx]/pow(4,n));
	}
}
