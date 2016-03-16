#include <bits/stdc++.h>
using namespace std;
int dp[110][5040];
int d[100],a[100],del[110];
map<vector<int>,int> encord;
map<int,vector<int> > decord;
int brute(int n){
	vector<int> v(n);
	for(int i=0;i<n;i++)v[i]=i;
	int ans=0,cnt=0;
	do{
		int tmp=0;
		memset(del,0,sizeof(del));
		for(int i=0;i<(int)v.size();i++){
			tmp+=del[v[i]];
			for(int j=max(0,v[i]-d[v[i]]);j<=min(n-1,v[i]+d[v[i]]);j++){
				del[j]+=a[v[i]];
			}
		}
		ans=max(ans,tmp);
		encord[v]=cnt;
		decord[cnt]=v;
		dp[n-1][cnt]=tmp;	cnt++;
	}while(next_permutation(v.begin(),v.end()));
	return ans;
}	

int main(){
	int n;	cin>>n;
	for(int i=0;i<n;i++)	cin>>d[i];
	for(int i=0;i<n;i++)	cin>>a[i];
	if(n<=7){
		cout<<brute(n)<<endl;
		return 0;
	}
	else 	brute(7);
	for(int i=7;i<n;i++){
		for(int j=0;j<5040;j++){
			vector<int> v=decord[j];
			vector<int> next(8),prv(7);
			for(int t=0;t<8;t++){//新しく食べるi番目の順番
				next[t]=7;
				for(int k=0;k<7;k++){
					if(k>=t)	next[k+1]=v[k];
					else 	next[k]=v[k];
				}
				int tmp=0;
				memset(del,0,sizeof(del));
				for(int k=0;k<8;k++){
					int pos=(i-7)+next[k];
					tmp+=del[pos];
					for(int l=max(i-7,pos-d[pos]);l<=min(i,pos+d[pos]);l++){
						if(l==i||pos==i)	del[l]+=a[pos];
					}
				}
				int cnt=0;
				for(int k=0;k<8;k++){
					if(next[k]!=0){
						prv[cnt]=next[k]-1;
						cnt++;
					}
				}
				int e=encord[prv];
				dp[i][e]=max(dp[i][e],dp[i-1][j]+tmp);
			}
		}
	}
	auto ans=max_element(dp[n-1],dp[n-1]+5040);
	cout<<*ans<<endl;
	return 0;
}
