#include <iostream>
#include <algorithm>
using namespace std;
const int inf=1<<29;
int dp[2][2][10010];//偶奇、AかBか、Aの持ってる長さ
int n,t[10010];
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++)	cin>>t[i];
	for(int i=0;i<10010;i++){
		dp[0][0][i]=dp[0][1][i]=dp[1][0][i]=dp[1][1][i]=inf;
	}
	dp[0][0][0]=0;
	for(int i=0;i<n;i++){
		int s=i&1;
		for(int j=0;j<=min(i,n/2);j++){
			dp[s^1][0][j+1]=min(dp[s][0][j],dp[s][1][j]+t[i]);
			dp[s^1][1][j]=min(dp[s][1][j],dp[s][0][j]+t[i]);
		}
		dp[s][0][0]=inf;
	}
	cout<<dp[0][0][n/2]<<endl;
	return 0;
}
