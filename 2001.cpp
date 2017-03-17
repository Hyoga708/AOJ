#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define fst first
#define scn second
int main(){
	while(true){
		int n,m,a;	cin>>n>>m>>a;
		if(n==0&&m==0&&a==0)	break;
		vector<pair<int,pair<int,int>>> ls;
		for(int i=0;i<m;i++){
			int h,p,q;	cin>>h>>p>>q;
			ls.push_back(make_pair(h,make_pair(p,q)));
		}
		sort(ls.begin(),ls.end());
		reverse(ls.begin(),ls.end());
		for(int i=0;i<m;i++){
			if(ls[i].scn.fst==a)	a=ls[i].scn.scn;
			else if(ls[i].scn.scn==a)	a=ls[i].scn.fst;
		}
		cout<<a<<endl;
	}
	return 0;
}
