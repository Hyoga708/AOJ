#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int price[]={10,50,100,500};
int have[4],ans[4],use[4];
int sml=1e9;
int x;

void solve(int cur){
	if(cur==4){
		int sum=0;
		for(int i=0;i<4;i++)	sum+=use[i]*price[i];
		sum-=x;
		if(sum<0)	return;
		int ret=0;
		for(int i=0;i<4;i++)	ret+=have[i]-use[i];
		ret+=sum/500;	sum%=500;
		ret+=sum/100;	sum%=100;
		ret+=sum/50;	sum%=50;
		ret+=sum/10;
		if(ret<sml){
			sml=ret;
			for(int i=0;i<4;i++)	ans[i]=use[i];
		}
	}
	else{
		for(int i=0;i<=have[cur];i++){
			use[cur]=i;
			solve(cur+1);
		}
	}
}

int main(){
	bool fst=true;
	while(true){
		cin>>x;
		if(x==0)	break;
		if(!fst)	cout<<endl;
		for(int i=0;i<4;i++)	cin>>have[i];
		sml=1e9;
		solve(0);
		for(int i=0;i<4;i++){
			if(ans[i]==0)	continue;
			cout<<price[i]<<" "<<ans[i]<<endl;
		}
		fst=false;
	}
	return 0;
}
