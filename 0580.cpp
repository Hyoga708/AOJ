#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> xx,yy,zz;
#undef int
int main(){
	#define int long long
	int N,K;	cin>>N>>K;
	vector<int> sx(N),tx(N),sy(N),ty(N),sz(N),tz(N);
	for(int i=0;i<N;i++){
		cin>>sx[i]>>sy[i]>>sz[i]>>tx[i]>>ty[i]>>tz[i];
		xx.push_back(sx[i]);	xx.push_back(tx[i]);
		yy.push_back(sy[i]);	yy.push_back(ty[i]);
		zz.push_back(sz[i]);	zz.push_back(tz[i]);
	}
	sort(xx.begin(),xx.end());	xx.erase(unique(xx.begin(),xx.end()),xx.end());
	sort(yy.begin(),yy.end());	yy.erase(unique(yy.begin(),yy.end()),yy.end());
	sort(zz.begin(),zz.end());	zz.erase(unique(zz.begin(),zz.end()),zz.end());
	int ans=0;
	for(int i=1;i<(int)xx.size();i++){
		for(int j=1;j<(int)yy.size();j++){
			for(int k=1;k<(int)zz.size();k++){
				int cnt=0;
				for(int l=0;l<N;l++){
					if(sx[l]<=xx[i-1]&&xx[i]<=tx[l]&&sy[l]<=yy[j-1]&&yy[j]<=ty[l]&&sz[l]<=zz[k-1]&&zz[k]<=tz[l]){
						cnt++;
					}
				}
				if(cnt>=K){
					ans+=(xx[i]-xx[i-1])*(yy[j]-yy[j-1])*(zz[k]-zz[k-1]);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
