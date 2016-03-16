#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;	cin>>s;
	int n=s.size();
	int ans=0;
	int now=0;
	while(now<n){
		while(now<n&&s[now]!='J')	now++;
		int jcnt=0;
		while(now+jcnt<n&&s[now+jcnt]=='J')	jcnt++;
		now+=jcnt;
		int ocnt=0;
		while(now+ocnt<n&&s[now+ocnt]=='O')	ocnt++;
		now+=ocnt;
		int icnt=0;
		while(now+icnt<n&&s[now+icnt]=='I')	icnt++;
		now+=icnt;
		int level=min(jcnt,min(ocnt,icnt));
		if(level!=ocnt)	continue;
		ans=max(ans,level);
	}
	cout<<ans<<endl;
	return 0;
}