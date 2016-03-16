#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[2010];
ll dp[2010][2010];//残りピース数、開始位置
int main(){
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)	dp[n-1][(i+1)%n]=a[i];//最初の１ピースの処理
	for(int i=n-1;i>0;i--){//ケーキの残り個数
		for(int j=0;j<n;j++){//ケーキの開始位置
			int k=(i+j-1)%n;//ケーキの終了位置
			if((n-i)&1){//IOIのターン
				if(a[j]<a[k])	dp[i-1][j]=max(dp[i-1][j],dp[i][j]);
				else 	dp[i-1][(j+1)%n]=max(dp[i-1][(j+1)%n],dp[i][j]);
			}
			else{//JOIのターン
				dp[i-1][j]=max(dp[i-1][j],dp[i][j]+a[k]);
				dp[i-1][(j+1)%n]=max(dp[i-1][(j+1)%n],dp[i][j]+a[j]);
			}
		}
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,dp[0][i]);
	}
	cout<<ans<<endl;
	return 0;
}
