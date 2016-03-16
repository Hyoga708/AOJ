#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll p[100010],sum[100010],a[100010],b[100010],c[100010];
int main(){
	int n,m;	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>p[i];	p[i]--;
	}
	for(int i=0;i<n-1;i++)	cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<m;i++){
		int s=p[i-1],t=p[i];
		if(s>t)	swap(s,t);
		sum[s]++;	sum[t]--;
	}
	for(int i=1;i<n-1;i++)	sum[i]+=sum[i-1];
	ll ans=0;
	for(int i=0;i<n-1;i++)	ans+=min(sum[i]*a[i],sum[i]*b[i]+c[i]);
	cout<<ans<<endl;
	return 0;
}