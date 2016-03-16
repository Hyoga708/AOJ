#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;	cin>>n;
	vector<int> u,v;
	for(int i=0;i<n;i++){
		int x,y;	cin>>x>>y;
		u.push_back(x+y);
		v.push_back(x-y);
	}
	int vmi=min_element(v.begin(),v.end())-v.begin();
	int umi=min_element(u.begin(),u.end())-u.begin();
	int vma=max_element(v.begin(),v.end())-v.begin();
	int uma=max_element(u.begin(),u.end())-u.begin();
	int val1=0,val2=0;
	for(int i=0;i<n;i++){
		val1=max(val1,min(
			max(max(abs(v[i]-v[vmi]),abs(v[i]-v[umi])),
				max(abs(u[i]-u[vmi]),abs(u[i]-u[umi]))),
			max(max(abs(v[i]-v[vma]),abs(v[i]-v[uma])),
				max(abs(u[i]-u[vma]),abs(u[i]-u[uma])))));
		val2=max(val2,min(
			max(max(abs(v[i]-v[vma]),abs(v[i]-v[umi])),
				max(abs(u[i]-u[vma]),abs(u[i]-u[umi]))),
			max(max(abs(v[i]-v[vmi]),abs(v[i]-v[uma])),
				max(abs(u[i]-u[vmi]),abs(u[i]-u[uma])))));
	}
	cout<<min(val1,val2)<<endl;
	return 0;
}
