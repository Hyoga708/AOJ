#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		for(int i=0;i<27;i++){
			string t=s;
			for(int j=0;j<(int)s.size();j++){
				if('a'<=t[j]&&t[j]<='z')	t[j]='a'+(t[j]-'a'+i)%26;
			}
			if(t.find("the",0)!=string::npos){
				cout<<t<<endl;
				break;
			}
			else if(t.find("that",0)!=string::npos){
				cout<<t<<endl;
				break;
			}
			else if(t.find("this",0)!=string::npos){
				cout<<t<<endl;
				break;
			}
		}
	}
	return 0;
}
