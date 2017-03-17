#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool used[64][64];
string s[64];
int main(){
	int n;	cin>>n;
	while(n--){
		int h,w;	cin>>h>>w;
		for(int i=0;i<h;i++)	for(int j=0;j<w;j++)	used[i][j]=false;
		for(int i=0;i<h;i++)	cin>>s[i];
		map<char,int> u,d,l,r;
		for(int i=0;i<h;i++)	for(int j=0;j<w;j++){
			if(s[i][j]!='.'){
				if(u.find(s[i][j])==u.end())	u[s[i][j]]=i;
				d[s[i][j]]=i;
				if(l.find(s[i][j])==l.end())	l[s[i][j]]=j;
				else 	l[s[i][j]]=min(l[s[i][j]],j);
				if(r.find(s[i][j])==r.end())	r[s[i][j]]=j;
				else 	r[s[i][j]]=max(r[s[i][j]],j);
			}
		}
		bool ok=true;
		int m=l.size();
		while(m){
			bool end=true;
			for(auto it:l){
				char key=it.first;
				int L=it.second;
				int R=r[key],U=u[key],D=d[key];
				//cout<<key<<" "<<U<<"-"<<D<<" "<<L<<"-"<<R<<endl;
				bool ok=true;
				for(int i=U;i<=D;i++){
					for(int j=L;j<=R;j++){
						if(s[i][j]==key||used[i][j])	continue;
						ok=false;
						break;
					}
					if(!ok)	break;
				}
				if(ok){
					m--;
					for(int i=U;i<=D;i++)	for(int j=L;j<=R;j++){
						used[i][j]=true;
					}
					u.erase(key);	d.erase(key);
					l.erase(key);	r.erase(key);
					end=false;
					break;
				}
			}
			if(end){
				cout<<"SUSPICIOUS"<<endl;
				break;
			}
		}
		if(m==0)	cout<<"SAFE"<<endl;
	}
	return 0;
}
