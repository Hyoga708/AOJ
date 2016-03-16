#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[100010];
int main(){
	int n,l;	cin>>n>>l;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	t[0]=l-a[0];
	for(int i=1;i<n;i++){
		if(a[i-1]>a[i])	t[i]=t[i-1]+(l-a[i]);
		else 	t[i]=l-a[i];
	}
	for(int i=n-2;i>=0;i--){
		if(a[i]<a[i+1])	t[i]=max(t[i],t[i+1]+(l-a[i]));
	}
	ll ans=0;
	for(int i=0;i<n;i++)	ans=max(ans,t[i]);
	cout<<ans<<endl;
	return 0;
}
