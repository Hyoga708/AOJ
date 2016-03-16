#include <bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		int k;	cin>>k;
		if(k==0)	return 0;
		int n=k*(k-1)/2;
		int sum=0;
		for(int i=0;i<n;i++){
			int c;	cin>>c;
			sum+=c;
		}
		cout<<sum/(k-1)<<endl;
	}
}
