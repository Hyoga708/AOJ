#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;	cin>>n;
	for(int i=0;i<n;i++){
		int k,p;	cin>>k>>p;
		if(k%p==0)	cout<<p<<endl;
		else 	cout<<k%p<<endl;
	}
	return 0;
}