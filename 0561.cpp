#include <bits/stdc++.h>
using namespace std;
int dp[11][2010];
int amount[10][2010];
int main(){
	int n,k;	cin>>n>>k;
	vector<int> a[10];
	for(int i=0;i<n;i++){
		int c,g;	cin>>c>>g;
		a[g-1].push_back(c);
	}
	for(int i=0;i<10;i++){
		sort(a[i].begin(),a[i].end());	reverse(a[i].begin(),a[i].end());
		int t=a[i].size();
		if(t==0)	continue;
		amount[i][0]=a[i][0];
		for(int j=1;j<t;j++)	amount[i][j]=a[i][j]+amount[i][j-1];
		for(int j=1;j<t;j++)	amount[i][j]+=j*(j+1);
	}
	int ans=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<k;j++){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			for(int l=0;l<(int)a[i].size();l++){
				if(j+1>k)	break;
				dp[i+1][j+l+1]=max(dp[i+1][j+l+1],dp[i][j]+amount[i][l]);
				ans=max(ans,dp[i+1][j+1]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}