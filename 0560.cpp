#include <bits/stdc++.h>
using namespace std;
int J[1010][1010],O[1010][1010],I[1010][1010];
int main(){
	int n,m,k;	cin>>m>>n>>k;
	memset(J,0,sizeof(J));	memset(O,0,sizeof(O));	memset(I,0,sizeof(I));
	for(int i=1;i<=m;i++){
		string s;	cin>>s;
		for(int j=1;j<=n;j++){
			if(s[j-1]=='J')	J[i][j]=1;
			else if(s[j-1]=='O')	O[i][j]=1;
			else I[i][j]=1;
			J[i][j]+=J[i-1][j]+J[i][j-1]-J[i-1][j-1];
			O[i][j]+=O[i-1][j]+O[i][j-1]-O[i-1][j-1];
			I[i][j]+=I[i-1][j]+I[i][j-1]-I[i-1][j-1];
		}
	}
	/*
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)	cout<<J[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)	cout<<O[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)	cout<<I[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	*/
	for(int t=0;t<k;t++){
		int a,b,c,d;	cin>>a>>b>>c>>d;	a--;	b--;
		int j=J[c][d]-J[a][d]-J[c][b]+J[a][b];
		int o=O[c][d]-O[a][d]-O[c][b]+O[a][b];
		int i=I[c][d]-I[a][d]-I[c][b]+I[a][b];
		cout<<j<<" "<<o<<" "<<i<<endl;
	}
	return 0;
}
