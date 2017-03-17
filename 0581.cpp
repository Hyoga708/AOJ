#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
typedef vector<p> vp;
typedef tuple<int,int,int,vp> state;
#define rep(i,n)	for(int i=0;i<n;i++)
#define mp	make_pair
#define mt	make_tuple

map<state,int> dp;
vector<string> s;
int h,w;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

void makeWall(){
	string a="";
	rep(i,s[0].size())	a+="#";
	s.insert(s.begin(),a);
	s.push_back(a);
	rep(i,s.size())	s[i]="#"+s[i]+"#";
}

int solve(int x,int y,int k,vp used){
	if(x==w&&y==h&&k==0)	return 0;
	state cur=mt(x,y,k,used);
	if(dp.find(cur)!=dp.end())	return dp[cur];
	int ret=INT_MIN;
	rep(d,4){
		int nx=x+dx[d];
		int ny=y+dy[d];
		int nk=k-(d>1);
		if(nk<0||s[ny][nx]=='#')	continue;
		vp nused;
		rep(i,used.size()){
			if((nx+ny)-(used[i].first+used[i].second)<=nk){
				nused.push_back(used[i]);
			}
		}
		int val=0;
		if(s[ny][nx]!='.'){
			auto it=lower_bound(nused.begin(),nused.end(),mp(nx,ny));
			if(it==nused.end()||*it!=mp(nx,ny)){
				val=s[ny][nx]-'0';
				nused.insert(it,mp(nx,ny));
			}
		}
		ret=max(ret,val+solve(nx,ny,nk,nused));
	}
	return dp[cur]=ret;
}

int main(){
	int k;	cin>>h>>w>>k;
	s.resize(h);
	rep(i,h)	cin>>s[i];
	makeWall();
	cout<<solve(1,1,k,vp())<<endl;
	return 0;
}
	
