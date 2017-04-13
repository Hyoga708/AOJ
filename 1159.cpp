#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	while(true){
		int n,p;	cin>>n>>p;
		if(n==0)	break;
		vector<int> a(n,0);
		int cur=0;
		int left=p;
		while(true){
			if(left){
				a[cur]++;
				left--;
			}
			else{
				left=a[cur];
				a[cur]=0;
			}
			if(left==0&&a[cur]==p)	break;
			cur=(cur+1)%n;
		}
		cout<<cur<<endl;
	}
	return 0;
}
