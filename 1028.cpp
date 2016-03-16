#include <bits/stdc++.h>
using namespace std;
const int kou[]={1,5,10,50,100,500};
int dp[7][700000];
int main(){
	while(true){
		int p;	cin>>p;
		if(p==0)	return 0;
		vector<int> n(6);
		for(int i=0;i<6;i++){
			cin>>n[i];
		}
		for(int i=0;i<7;i++){
			dp[i][0]=0;
			for(int j=1;j<700000;j++)	dp[i][j]=1<<25;
		}
		int end=0;
		for(int i=0;i<6;i++){
			end+=n[i]*kou[i];
			for(int a=0;a<kou[i];a++){
				deque<pair<int,int>> dq;//値、インデックス
				for(int j=0;j*kou[i]+a<=end;j++){
					int val=dp[i][j*kou[i]+a]-j;
					while(!dq.empty()&&dq.back().first>=val)	dq.pop_back();
					dq.push_back(make_pair(val,j));
					dp[i+1][j*kou[i]+a]=dq.front().first+j;
					while(!dq.empty()&&j-dq.front().second>=n[i])	dq.pop_front();
				}
			}
		}
		int ans=INT_MAX;
		for(int i=p;i<=end;i++){
			int tmp=dp[6][i],v=i-p;
			int tmp2=0;
			for(int j=5;j>=0;j--){
				tmp2+=v/kou[j];	v%=kou[j];
			}
			ans=min(ans,tmp+tmp2);
		}
		cout<<ans<<endl;
	}
}
