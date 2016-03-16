#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int n,m,sx,sy,num;
int grd[11][11];
const int mx[]={1,0,-1,0},my[]={0,1,0,-1};
int dfs(int x,int y){
	if(num==0)	return (x==sx||y==sy);
	int ans=0;
	grd[y][x]=0;
	rep(i,4){
		int tx=x+mx[i],ty=y+my[i];
		while(0<=tx&&tx<n&&0<=ty&&ty<m){
			if(grd[ty][tx]==1){
				num--;
				ans+=dfs(tx,ty);
				num++;
				break;
			}
			tx+=mx[i];	ty+=my[i];
		}
	}
	grd[y][x]=1;
	return ans;
}

int main(){
	while(true){
		cin>>n>>m;
		if(n==0)	return 0;
		memset(grd,0,sizeof(grd));
		num=0;
		rep(i,m)	rep(j,n){
			cin>>grd[i][j];
			if(grd[i][j]==2){
				sx=j,sy=i;
			}
			else if(grd[i][j]==1)	num++;
		}
		cout<<dfs(sx,sy)<<endl;
	}
}
