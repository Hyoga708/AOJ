#include <bits/stdc++.h>
using namespace std;
int grid[110][110];
int main(){
	int w,h;	cin>>w>>h;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)	cin>>grid[i][j];
	}
	w++;	h++;
	queue<pair<int,int>> q;	q.push(make_pair(0,0));	grid[0][0]=-1;
	int mx[2][6]={{-1,0,-1,1,-1,0},{0,1,-1,1,0,1}};
	int my[2][6]={{-1,-1,0,0,1,1},{-1,-1,0,0,1,1}};
	while(!q.empty()){
		auto now=q.front();	q.pop();
		int y=now.first,x=now.second;
		int u=y%2;
		for(int i=0;i<6;i++){
			int ny=y+my[u][i],nx=x+mx[u][i];
			if(!(0<=ny&&ny<=h)||!(0<=nx&&nx<=w))	continue;
			if(grid[ny][nx]==0){
				grid[ny][nx]=-1;
				q.push(make_pair(ny,nx));
			}
		}
	}
	int ans=0;
	for(int i=1;i<h;i++){
		int u=i%2;
		for(int j=1;j<w;j++){
			if(grid[i][j]==1){
				for(int k=0;k<6;k++){
					if(grid[i+my[u][k]][j+mx[u][k]]==-1)	ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
