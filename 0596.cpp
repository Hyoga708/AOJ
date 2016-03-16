#include <bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;
int dp[5000];
vector<int> ls[5000];
int c[5000],r[5000];
int main(){
	int n,k;	cin>>n>>k;
	for(int i=0;i<n;i++)	cin>>c[i]>>r[i];
	for(int i=0;i<k;i++){
		int a,b;	cin>>a>>b;	a--;	b--;
		ls[a].push_back(b);	ls[b].push_back(a);
	}
	for(int i=0;i<n;i++)	dp[i]=inf;
	dp[0]=0;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0,0));
	while(!pq.empty()){
		auto tp=pq.top();	pq.pop();
		int cost=-tp.first,cur=tp.second;
		//cout<<cur<<" "<<cost<<endl;
		if(cost>dp[cur])	continue;
		if(cur==n-1){
			cout<<cost<<endl;
			return 0;
		}
		cost+=c[cur];
		set<int> visited;	visited.insert(cur);
		set<int> now,next;	now.insert(cur);
		for(int i=0;i<r[cur];i++){
			for(auto it=now.begin();it!=now.end();it++){
				for(int j=0;j<(int)ls[*it].size();j++){
					if(visited.find(ls[*it][j])==visited.end()){
						visited.insert(ls[*it][j]);
						next.insert(ls[*it][j]);
						if(dp[ls[*it][j]]>cost){
							dp[ls[*it][j]]=cost;
							pq.push(make_pair(-cost,ls[*it][j]));
						}
					}
				}
			}
			now=next;
		}
	}
	return 0;
}
		
