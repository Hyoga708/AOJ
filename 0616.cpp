#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1ll<<60;
vector<ll> to[100000],cost[100000],rev[100000];
bool used[100000];
int main(){
	int n,m,c;	cin>>n>>m>>c;
	ll esum=0;
	for(int i=0;i<m;i++){
		ll a,b,d;	cin>>a>>b>>d;	a--;	b--;
		to[a].push_back(b);	cost[a].push_back(d);	rev[a].push_back(to[b].size());
		to[b].push_back(a);	cost[b].push_back(d);	rev[b].push_back(to[a].size()-1);
		esum+=d;
	}
	vector<ll> dist(n,inf);	dist[0]=0;
	priority_queue<pair<ll,ll> > pq;
	pq.push(make_pair(0,0));
	while(!pq.empty()){
		auto now=pq.top();	pq.pop();
		ll cc=-now.first,x=now.second;
		for(int i=0;i<(int)to[x].size();i++){
			if(dist[to[x][i]]>cc+cost[x][i]){
				dist[to[x][i]]=cc+cost[x][i];
				pq.push(make_pair(-dist[to[x][i]],to[x][i]));
			}
		}
	}
	map<ll,vector<ll> > data;
	for(int i=0;i<n;i++)	data[dist[i]].push_back(i);
	used[0]=true;
	ll ans=inf;
	for(auto it=data.begin();it!=data.end();it++){
		ll cc=it->first;
		vector<ll> vec=it->second;
		for(int i=0;i<(int)vec.size();i++){
			int x=vec[i];
			used[x]=true;
			for(int j=0;j<(int)to[x].size();j++){
				if(used[to[x][j]]){
					esum-=cost[x][j];
					cost[to[x][j]][rev[x][j]]=0;
				}
			}
		}
		ans=min(ans,esum+c*cc);
	}
	cout<<ans<<endl;
	return 0;
}
