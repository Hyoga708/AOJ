#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll cur,int n){//判定
	int cnt=0;
	ll tmp=cur;
	while(tmp){	tmp/=10;	cnt++;	}
	if(cnt!=2*n+1)	return false;
	if(cur%2==0)	return false;
	for(int i=3;i*i<=cur;i+=2){//curは２桁以上が保証されている
		if(cur%i==0)	return false;
	}
	return true;
}
	
ll dfs(int n,int c,ll cur,int keta){
	if(n==keta){
		ll rev=cur,tans=cur*10+c;
		while(rev){
			tans=tans*10+(rev%10);
			rev/=10;
		}
		if(check(tans,n))	return tans;
		else 	return -1;
	}
	else{
		for(int i=9;i>=0;i--){
			ll tans=dfs(n,c,cur*10+i,keta+1);
			if(tans>0)	return tans;
		}
		return -1;
	}
}

int main(){
	int n,c;	cin>>n>>c;
	if(c<0){//回分なので必ず１１で割れる。
		if(n==1){
			cout<<11<<endl;
			return 0;
		}
		for(int i=0;i<2*n;i++)	cout<<9;
		cout<<endl;
		return 0;
	}
	ll ans=dfs(n,c,0,0);//最後のケースはc<0、それ以外はn<5なのでOK
	if(ans<0){
		for(int i=0;i<n;i++)	cout<<9;
		cout<<c;
		for(int i=0;i<n;i++)	cout<<9;
	}
	else 	cout<<ans;
	cout<<endl;
	return 0;
}
	
