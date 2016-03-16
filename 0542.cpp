#include <bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int maps[2][510][510];
bool visited[2][510][510];
int cnt[2][250010];
int r,w[2],h[2],sx[2],sy[2];
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
void calc(){
	for(int k=0;k<2;k++){
		int room=0,level=0;
		priority_queue<tuple<int,int,int>> pq;
		for(int i=0;i<=h[k];i++)	visited[k][i][0]=visited[k][i][w[k]+1]=true;
		for(int i=0;i<=w[k];i++)	visited[k][0][i]=visited[k][h[k]+1][i]=true;
		pq.push(make_tuple(-1,sx[k],sy[k]));
		while(!pq.empty()&&room<h[k]*w[k]){
			auto now=pq.top();	pq.pop();
			int l=-get<0>(now),x=get<1>(now),y=get<2>(now);
			if(visited[k][y][x])	continue;
			visited[k][y][x]=true;
			if(level<l)	level=l;
			room++;	cnt[k][room]=level;
			for(int i=0;i<4;i++){
				int ny=y+dy[i],nx=x+dx[i];
				if(visited[k][ny][nx])	continue;
				pq.push(make_tuple(-maps[k][ny][nx],nx,ny));
			}
		}
	}
}
int main(){
	while(true){
		cin>>r;
		if(r==0)	return 0;
		memset(maps,0,sizeof(maps));
		for(int k=0;k<2;k++){
			for(int i=1;i<100010;i++) cnt[k][i]=inf;
			cnt[k][0]=0;
			for(int i=0;i<510;i++){
				for(int j=0;j<510;j++)	visited[k][i][j]=false;
			}
		}
		for(int k=0;k<2;k++){
			cin>>w[k]>>h[k]>>sx[k]>>sy[k];
			for(int i=1;i<=h[k];i++){//区画の外側を壁で覆う
				for(int j=1;j<=w[k];j++)	cin>>maps[k][i][j];
			}
		}
		calc();
		for(int k=0;k<2;k++){
			int tmp=inf;
			for(int i=w[k]*h[k];i>=0;i--){
				tmp=min(tmp,cnt[k][i]);
				cnt[k][i]=tmp;
			}
		}
		int ans=inf;
		for(int i=0;i<=r;i++){
			if(i>h[0]*w[0]||r-i>h[1]*w[1])	continue;
			ans=min(ans,cnt[0][i]+cnt[1][r-i]);
		}
		cout<<ans<<endl;
	}
}
