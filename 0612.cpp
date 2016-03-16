#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ip;
const int MAX=1010;
int cnt[MAX][MAX];
int mx[]={1,1,1,0,0,-1,-1,-1},my[]={1,0,-1,1,-1,1,0,-1};
int main(){
	int h,w;	cin>>h>>w;
	vector<string> s(h);
	for(int i=0;i<h;i++)	cin>>s[i];
	queue<ip> q;
	for(int i=0;i<h;i++){//各地点の周りにいくつ更地があるかカウント
		for(int j=0;j<w;j++){
			if(s[i][j]=='.')	continue;
			for(int k=0;k<8;k++){
				if(s[i+my[k]][j+mx[k]]=='.')	cnt[i][j]++;
			}
			if(cnt[i][j]>=s[i][j]-'0'){//壊せるなら壊す
				s[i][j]='0';
				q.push(make_pair(i,j));
			}
		}
	}
	if(q.empty()){
		cout<<0<<endl;
		return 0;
	}
	int ans=1;
	while(true){
		queue<pair<int,int>> broken;
		while(!q.empty()){
			auto now=q.front();	q.pop();
			int y=now.first,x=now.second;
			for(int i=0;i<8;i++){//壊れた地点の周りのカウントを＋１。
				int yy=y+my[i],xx=x+mx[i];
				if(s[yy][xx]=='.'||s[yy][xx]=='0')	continue;
				cnt[yy][xx]++;
				if(cnt[yy][xx]>=s[yy][xx]-'0'){
					s[yy][xx]='0';
					broken.push(make_pair(yy,xx));
				}
			}
		}
		if(broken.empty()){
			cout<<ans<<endl;
			return 0;
		}
		while(!broken.empty()){
			q.push(broken.front());	broken.pop();
		}
		ans++;
	}
}