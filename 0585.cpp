#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int N;
P a[500000];
bool compare_y(P a,P b){
	return a.second<b.second;
}
ll closest_pair(P *a,int n){
	if(n<=1)	return LLONG_MAX;
	int m=n/2;
	ll x=a[m].first;
	ll d=min(closest_pair(a,m),closest_pair(a+m,n-m));
	inplace_merge(a,a+m,a+n,compare_y);
	vector<P> b;
	for(int i=0;i<n;i++){
		if(llabs(a[i].first-x)>=d)	continue;
		for(int j=0;j<(int)b.size();j++){
			ll dx=a[i].first-b[b.size()-j-1].first;
			ll dy=a[i].second-b[b.size()-j-1].second;
			if(dy>=d)	break;
			d=min(d,dx*dx+dy*dy);
		}
		b.push_back(a[i]);
	}
	return d;
}
void solve(){
	sort(a,a+N);
	printf("%lld\n",closest_pair(a,N));
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%lld %lld",&a[i].first,&a[i].second);
	}
	solve();
	return 0;
}
