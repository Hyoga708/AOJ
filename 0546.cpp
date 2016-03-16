#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n,k;
vector<int> num;
void dfs(int t,int ret,vector<int> use){
	if(t==k)	s.insert(ret);
	else{
		for(int i=0;i<n;i++){
			if(use[i])	continue;
			use[i]=1;
			if(num[i]<10)	dfs(t+1,ret*10+num[i],use);
			else 	dfs(t+1,ret*100+num[i],use);
			use[i]=0;
		}
	}
}
int main(){
	while(true){
		cin>>n>>k;
		if(n==0)	return 0;
		s.clear();
		num.clear();
		for(int i=0;i<n;i++){
			int a;	cin>>a;
			num.push_back(a);
		}
		dfs(0,0,vector<int>(n,0));
		cout<<s.size()<<endl;
	}
}