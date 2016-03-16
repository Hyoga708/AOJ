#include <bits/stdc++.h>
using namespace std;
//BITを用いる解法O(mlogn)
const int mod=1e5;
int n,m;
const int bitsize=(1<<20);
int s[100010];
int a[100010];
long long bit[bitsize];
void makebit(){
	for(int i=1;i<n;i++){//扱いやすさの都合上0は用いない
		int now=i;
		while(now<bitsize){
			bit[now]+=s[i];
			now+=(now&-now);
		}
	}
	for(int i=0;i<bitsize;i++)	bit[i]%=mod;
}
int cntbit(int now){
	now--;
	int ans=0;
	while(now>0){
		ans+=bit[now];	ans%=mod;
		now-=now&-now;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<n;i++)	cin>>s[i];
	makebit();
	int now=1;
	int ans=0;
	for(int i=0;i<m;i++){
		cin>>a[i];
		int next=now+a[i];
		if(a[i]>0)	ans+=cntbit(next)-cntbit(now);
		else 	ans+=cntbit(now)-cntbit(next);
		ans%=mod;
		now=next;
	}
	cout<<ans<<endl;
	return 0;
}