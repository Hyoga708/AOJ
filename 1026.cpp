#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	while(true){
		ll n;	cin>>n;
		if(n==0) 	return 0;
		ll ans=8*n;// 底面積
		ll ans2=n/2;
		ll w=1;
		for(;w*w<n/2;w++){
			ans2+=(n+2*w-1)/(2*w);
		}
		ans2=2*ans2-w*w;
		if(n&1)	ans2++;
		ll s=ans+ans2*8;
		cout<<s<<endl;
	}
}
