#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=1<<30;
typedef long long ll;
int main(){
	int n;	cin>>n;
	map<int,int> lib;
	for(int i=0;i<n;i++){
		int a;	cin>>a;
		lib[a]++;
	}
	lib[inf]=5;
	vector<int> ls;
	auto it=lib.begin();
	while(ls.size()<5){
		while(ls.size()<5&&it->second>0){
			it->second--;
			ls.push_back(it->first);
		}
		it++;
	}
	vector<ll> ans;
	for(int i=0;i<(int)ls.size();i++){
		for(int j=0;j<(int)ls.size();j++){
			if(i==j)	continue;
			ll a=ls[i],b=ls[j];
			if(a==inf||b==inf)	continue;
			for(ll j=1;b/j>0;j*=10)	a*=10;
			ans.push_back(a+b);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans[2]<<endl;
	return 0;
}
