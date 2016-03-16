#include <bits/stdc++.h>
using namespace std;
vector<int> ls[100];
bool visited[100];
int dfs(int now,int l){
	int ans=l;
	visited[now]=true;
	for(int i=0;i<(int)ls[now].size();i++){
		if(visited[ls[now][i]])	continue;
		ans=max(ans,dfs(ls[now][i],l+1));
	}
	visited[now]=false;
	return ans;
}
int main(){
	while(true){
		int n;	cin>>n;
		if(n==0)	return 0;
		for(int i=0;i<100;i++)	ls[i].clear();
		set<int> uses;
		for(int i=0;i<n;i++){
			int a,b;	cin>>a>>b;	a--;	b--;
			uses.insert(a);	uses.insert(b);
			ls[a].push_back(b);	ls[b].push_back(a);
		}
		int ans=0;
		for(auto it=uses.begin();it!=uses.end();it++){
			ans=max(ans,dfs(*it,1));
		}
		cout<<ans<<endl;
	}
}
