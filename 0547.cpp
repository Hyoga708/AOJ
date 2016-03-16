#include <bits/stdc++.h>
using namespace std;
const int mod=100000;
int dp[100][100][2][2];//0:曲がってない,1:曲がった	0:北向き,1:東向き
int main(){
	int w,h;
	while(true){
		cin>>w>>h;
		if(w==0)	return 0;
		memset(dp,0,sizeof(dp));
		dp[1][0][0][0]=dp[0][1][0][1]=1;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				int out=0;
				for(int k=0;k<2;k++)
					for(int l=0;l<2;l++)
						dp[i][j][k][l]%=mod,out+=dp[i][j][k][l];
				if(i+1<h){//縦に移動
					dp[i+1][j][0][0]+=dp[i][j][0][0]+dp[i][j][1][0];
					dp[i+1][j][1][0]+=dp[i][j][0][1];
				}
				if(j+1<w){//横に移動
					dp[i][j+1][0][1]+=dp[i][j][0][1]+dp[i][j][1][1];
					dp[i][j+1][1][1]+=dp[i][j][0][0];
				}
			}
		}
		int ans=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)	ans+=dp[h-1][w-1][i][j];
		ans%=mod;
		cout<<ans<<endl;
	}
}
					
				
