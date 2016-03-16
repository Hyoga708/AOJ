#include <bits/stdc++.h>
using namespace std;
int main(){
	int d;
	while(true){
		cin>>d;
		if(d==0)	return 0;
		int n,m;	cin>>n>>m;
		vector<int> shop(n+1);	shop[0]=0,shop[n]=d;
		for(int i=1;i<n;i++){
			int dist;	cin>>dist;
			shop[i]=dist;
		}
		sort(shop.begin(),shop.end());
		long long ans=0;
		for(int i=0;i<m;i++){
			int k;	cin>>k;
			vector<int>::iterator it=lower_bound(shop.begin(),shop.end(),k);
			long long tmp1=*it-k;
			if(it!=shop.begin())	it--;
			long long tmp2=k-*it;
			ans+=min(tmp1,tmp2);
		}
		cout<<ans<<endl;
	}
}