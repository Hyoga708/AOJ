#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b;	cin>>a>>b;
	vector<int> ac(a),bc(b);
	for(int i=0;i<a;i++)	cin>>ac[i];
	for(int j=0;j<b;j++)	cin>>bc[j];
	int ans=0;
	for(int i=0;i<b;i++){
		int tmp=0;
		int n=i;
		for(int j=0;j<a&&n<b;j++){
			if(bc[n]==ac[j])	tmp++,n++;
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}