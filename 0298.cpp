#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;	cin>>n;
	vector<int> nt(n);
	for(int i=0;i<n;i++){
		int h,m;	cin>>h>>m;
		nt[i]=h*60+m;
	}
	nt.push_back(1<<30);
	int m;	cin>>m;
	vector<int> mt(m);
	for(int i=0;i<m;i++){
		int k,g;	cin>>k>>g;
		mt[i]=k*60+g;
	}
	mt.push_back(1<<30);
	int ncnt=0,mcnt=0;
	bool f=false;
	while(true){
		if(ncnt==n&&mcnt==m)	break;
		if(f)	cout<<" ";
		f=true;
		if(nt[ncnt]<mt[mcnt]){
			int k=nt[ncnt]/60,g=nt[ncnt++]%60;
			printf("%d:%02d",k,g);
		}
		else if(nt[ncnt]>mt[mcnt]){
			int k=mt[mcnt]/60,g=mt[mcnt++]%60;
			printf("%d:%02d",k,g);
		}
		else{
			int k=nt[ncnt]/60,g=nt[ncnt]%60;
			printf("%d:%02d",k,g);
			ncnt++;	mcnt++;
		}
	}
	cout<<endl;
	return 0;
}