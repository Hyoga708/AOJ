#include <bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		int n,k;	cin>>n>>k;
		if(n==0)	return 0;
		vector<int> s(k);
		for(int i=0;i<k;i++)	cin>>s[i];
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				int b;	cin>>b;
				s[j]-=b;
			}
		}
		for(int i=0;i<k;i++){
			if(s[i]<0){
				cout<<"No"<<endl;
				goto next;
			}
		}
		cout<<"Yes"<<endl;
		next:;
	}
}
