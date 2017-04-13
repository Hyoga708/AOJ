#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
#define mp(a,b)	make_pair(a,b)
#define fst first
#define scn second


bool edge[50][50][4];
int dist[50][50];
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
const int inf=1e9;
int main(){
	while(true){
		int w,h;	cin>>w>>h;
		if(w==0)	break;
		for(int i=0;i<50;i++)	for(int j=0;j<50;j++){
			for(int k=0;k<4;k++)	edge[i][j][k]=false;
			dist[i][j]=inf;
		}
		for(int i=1;i<w;i++){
			int c;	cin>>c;
			if(c==0)	edge[0][i-1][0]=edge[0][i][2]=true;
		}
		for(int i=1;i<h;i++){
			for(int j=0;j<w;j++){
				int c;	cin>>c;
				if(c==0)	edge[i-1][j][1]=edge[i][j][3]=true;
			}
			for(int j=1;j<w;j++){
				int c;	cin>>c;
				if(c==0)	edge[i][j-1][0]=edge[i][j][2]=true;
			}
		}
		dist[0][0]=1;
		priority_queue<pair<int,pii> > pq;
		pq.push(mp(-1,mp(0,0)));
		while(!pq.empty()){
			auto it=pq.top();	pq.pop();
			int d=-it.fst;
			int y=it.scn.fst;
			int x=it.scn.scn;
			if(dist[y][x]<d)	continue;
			d++;
			for(int i=0;i<4;i++){
				if(!edge[y][x][i])	continue;
				if(dist[y+dy[i]][x+dx[i]]>d){
					dist[y+dy[i]][x+dx[i]]=d;
					pq.push(mp(-d,mp(y+dy[i],x+dx[i])));
				}
			}
		}
		if(dist[h-1][w-1]==inf)	dist[h-1][w-1]=0;
		cout<<dist[h-1][w-1]<<endl;
	}
	return 0;
}