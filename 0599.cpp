#include <bits/stdc++.h>
using namespace std;
const int inf=1<<30;
vector<int> p,c,e;
int dp[510][10010];
int main(){
	int n,m;	cin>>m>>n;
	p.resize(m);	c.resize(n);	e.resize(n);
	for(int i=0;i<m;i++)	cin>>p[i];
	//饅頭はソートして価値の高い順に使う。
	sort(p.begin(),p.end());	reverse(p.begin(),p.end());
	for(int i=0;i<n;i++)	cin>>c[i]>>e[i];
	//dp[i][j]:i個の饅頭を使うのに必要な箱の価格の最小値
	for(int i=0;i<510;i++)	fill_n(dp[i],10010,inf);
	dp[0][0]=0;
	for(int i=1;i<=c[0];i++)	dp[0][i]=e[0];
	for(int i=1;i<n;i++){
		dp[i][0]=0;
		for(int j=1;j<=m;j++){
			if(j<c[i])	dp[i][j]=min(dp[i-1][j],e[i]);
			else 	dp[i][j]=min(dp[i-1][j],dp[i-1][j-c[i]]+e[i]);
		}
	}
	int sum=0,ans=0;
	for(int i=0;i<m;i++){
		sum+=p[i];
		ans=max(ans,sum-dp[n-1][i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
