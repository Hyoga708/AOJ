#include <bits/stdc++.h>
using namespace std;
int depth[510];
vector<int> edge[510];
int main(){
	int n,m;
	while(true){
		cin>>n>>m;
		if(n==0)	return 0;
		for(int i=0;i<510;i++)	edge[i].clear();
		for(int i=0;i<m;i++){
			int a,b;	cin>>a>>b;	a--;	b--;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for(int i=0;i<510;i++)	depth[i]=-1;
		depth[0]=0;
		queue<int> q;	q.push(0);
		set<int> ans;
		while(!q.empty()){
			int now=q.front();	q.pop();
			if(depth[now]>=2)	continue;
			for(int i=0;i<(int)edge[now].size();i++){
				int next=edge[now][i];
				if(depth[next]==-1){
					depth[next]=depth[now]+1;
					q.push(next);
					ans.insert(next);
				}
			}
		}
		cout<<ans.size()<<endl;
	}	
}
