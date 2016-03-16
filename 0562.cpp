#include <bits/stdc++.h>
using namespace std;
const int inf=1<<30;
struct edge{	int to,cost;	};
int main(){
	int n,m,k;	cin>>n>>m>>k;
	vector<edge> e[n];
	vector<int> dist(n,inf);
	for(int i=0;i<m;i++){
		int a,b,l;	cin>>a>>b>>l;	a--;	b--;
		e[a].push_back((edge){b,l});
		
		e[b].push_back((edge){a,l});
	}
	for(int i=0;i<k;i++){
		int s;	cin>>s;	s--;
		dist[s]=0;
		queue<int> q;	q.push(s);
		while(!q.empty()){
			int now=q.front();	q.pop();
			for(int i=0;i<(int)e[now].size();i++){
				if(dist[e[now][i].to]>dist[now]+e[now][i].cost){
					dist[e[now][i].to]=dist[now]+e[now][i].cost;
					q.push(e[now][i].to);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<(int)e[i].size();j++){
			ans=max(ans,(dist[i]+dist[e[i][j].to]+e[i][j].cost+1)/2);
		}
	}
	cout<<ans<<endl;
	return 0;
}
