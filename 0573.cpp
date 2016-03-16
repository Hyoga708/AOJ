#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll dp1[3030],dp2[3030];
int main(){
	int n,t,s;	cin>>n>>t>>s;
	vector<int> a(n),b(n);
	rep(i,n)	cin>>a[i]>>b[i];
	ll ans=0;
	rep(i,n){
		rep(j,t){
			dp2[j]=max(dp2[j],dp1[j]);//その屋台をスキップ
			if(j<t)	dp1[j+1]=max(dp1[j+1],dp1[j]);//その時間は何もしない
			if(j+b[i]<=t){//その屋台で遊ぶ
				if(j<s&&s<j+b[i])	continue;
				dp2[j+b[i]]=max(dp2[j+b[i]],dp1[j]+a[i]);
				ans=max(ans,dp2[j+b[i]]);
			}
		}
		rep(j,3030){
			dp1[j]=dp2[j];
			dp2[j]=0;
		}
	}
	cout<<ans<<endl;
}