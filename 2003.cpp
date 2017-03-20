#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define fst first
#define scn second

complex<int> rot;
void rotate(pii *p){
	complex<int> P(p->fst,p->scn);
	P*=rot;
	*p=mp(P.real(),P.imag());
}

pii getpair(){
	pii ret;
	cin>>ret.fst>>ret.scn;
	return ret;
}

int main(){
	int m;	cin>>m;
	while(m--){
		pii s=getpair(),t=getpair();
		rot=complex<int>(s.scn-t.scn,s.fst-t.fst);
		rotate(&s);	rotate(&t);
		if(s.scn>t.scn)	swap(s,t);
		int n;	cin>>n;
		vector<pair<double,int>> ls;
		for(int i=0;i<n;i++){
			pii p=getpair(),q=getpair();
			int o,l;	cin>>o>>l;
			if(o==0)	l^=1;
			rotate(&p);	rotate(&q);
			if(p.fst==q.fst)	continue;
			double r=(double)(s.fst-q.fst)/(p.fst-q.fst);
			if(r<0||1<r)	continue;
			double y=(p.scn-q.scn)*r+q.scn;
			if(s.scn<=y&&y<=t.scn){
				ls.push_back(mp(y,l));
			}
		}
		sort(ls.begin(),ls.end());
		int ret=0;
		for(int i=1;i<ls.size();i++){
			if(ls[i].scn!=ls[i-1].scn)	ret++;
		}
		cout<<ret<<endl;
	}
	return 0;
}
