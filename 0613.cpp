#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
ll x[30],y[30];
vector<pair<ll,ll>> s[2];
void dfs(int id,int now,int end,ll a,ll b){//半分全列挙
	if(now==end){
		s[id].push_back(make_pair(a,b));
		return;
	}
	dfs(id,now+1,end,a+x[now],b+y[now]);
	dfs(id,now+1,end,a-x[now],b-y[now]);
	dfs(id,now+1,end,a,b);
}

int main(){
	cin>>n>>d;
	for(int i=0;i<n;i++)	cin>>x[i]>>y[i];
	dfs(0,0,n/2,0,0);	dfs(1,n/2,n,0,0);
	sort(s[0].begin(),s[0].end());	sort(s[1].begin(),s[1].end());
	//+はA君が盗った。-はB君が盗った
	ll ans=0;
	int cnt=0;
	deque<pair<ll,ll>> dq;
	for(int i=0;i<(int)s[0].size();i++){
		while(cnt<(int)s[1].size()&&s[1][cnt].first<=s[0][i].first+d){
			while(!dq.empty()&&dq.back().second>s[1][cnt].second)	dq.pop_back();	
			dq.push_back(s[1][cnt]);
			cnt++;
		}
		while(!dq.empty()&&dq.front().first<s[0][i].first-d)	dq.pop_front();
		if(!dq.empty())	ans=max(ans,s[0][i].second-dq.front().second);
	}
	cout<<ans<<endl;
}
