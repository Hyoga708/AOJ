#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define mp make_pair
#define fst first
#define scn second
int main(){
	while(true){
		int n,m,s,g1,g2;	cin>>n>>m>>s>>g1>>g2;
		if(n==0)	break;
		s--;	g1--;	g2--;
		vector<vector<ll>> dist(n,vector<ll>(n,1e9));
		for(int i=0;i<n;i++)	dist[i][i]=0;
		for(int i=0;i<m;i++){
			int f,t,d;	cin>>f>>t>>d;
			f--;	t--;
			dist[f][t]=d;
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		ll ret=1e9;
		for(int i=0;i<n;i++){
			ret=min(ret,dist[s][i]+dist[i][g1]+dist[i][g2]);
		}
		cout<<ret<<endl;
	}
	return 0;
}
