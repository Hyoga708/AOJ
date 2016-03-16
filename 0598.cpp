#include <bits/stdc++.h>
using namespace std;
string joi="JOI";
string s[1000],f[2];
int cnt[1000][1000];
int main(){
	int m,n;	cin>>m>>n;
	for(int i=0;i<m;i++)	cin>>s[i];
	for(int i=0;i<2;i++)	cin>>f[i];
	int tmp=0;
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(s[i-1][j-1]==f[0][0]&&s[i-1][j]==f[0][1]&&s[i][j-1]==f[1][0]&&s[i][j]==f[1][1]){
				tmp++;
				cnt[i-1][j-1]++;	cnt[i-1][j]++;	cnt[i][j-1]++;	cnt[i][j]++;
			}
		}
	}
	int ans=tmp;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){//s[i][j]をjoi[k]にした時
				int count=0;
				for(int a=-1;a<1;a++){
					for(int b=-1;b<1;b++){//左上がs[i+a][j+b]の正方形を考える
						int r=i+a,c=j+b;
						if(r<0||c<0)	continue;
						if(r+1>=m||c+1>=n)	continue;
						string ts[]={"  ","  "};
						for(int y=0;y<2;y++){
							for(int x=0;x<2;x++){
								if(r+y==i&&c+x==j)	ts[y][x]=joi[k];
								else 	ts[y][x]=s[r+y][c+x];
							}
						}
						if(ts[0]==f[0]&&ts[1]==f[1])	count++;
					}
				}
				ans=max(ans,tmp-cnt[i][j]+count);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
