#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
	while(true){
		int n,m,h,k;	cin>>n>>m>>h>>k;
		if(n==0)	return 0;
		vector<int> s(n);
		for(int i=0;i<n;i++)	cin>>s[i];
		vector<pii> d;
		for(int i=0;i<m;i++){
			int a,b;	cin>>a>>b;	a--;
			d.push_back(make_pair(b,a));
		}
		sort(d.begin(),d.end());
		vector<int> point(n),iti(n);
		for(int i=0;i<n;i++)	iti[i]=i;
		vector<pii> e(m);
		for(int i=0;i<m;i++){
			e[i].first=iti[d[i].second];	e[i].second=iti[d[i].second+1];
			swap(iti[d[i].second],iti[d[i].second+1]);
		}
		for(int i=0;i<n;i++)	point[iti[i]]=s[i];
		int sum=0;
		for(int i=0;i<k;i++)	sum+=point[i];
		int ans=sum;
		for(int i=0;i<m;i++){
			int a=e[i].first,b=e[i].second;
			if(a>b)	swap(a,b);
			if(a<k&&k<=b){
				int tmp=sum-point[a]+point[b];
				ans=min(ans,tmp);
			}
		}
		cout<<ans<<endl;
	}
}
