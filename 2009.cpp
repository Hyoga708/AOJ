#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<double,double> pdd;
#define mp make_pair
#define fst first
#define scn second
const double eps=1e-11;
pdd findPoint(pdd a,pdd b,pdd c,pdd d){
	//(a.fst-b.fst)*(y-a.scn)=(a.scn-b.scn)*(x-a.fst)
	//(b.scn-a.scn)x+(a.fst-b.fst)y=a.scn(a.fst-b.fst)-a.fst(a.scn-b.scn)
	//(d.scn-c.scn)x+(c.fst-d.fst)y=c.scn(c.fst-d.fst)-c.fst(c.scn-d.scn)
	//ax+by=c
	//dx+ey=f
	//(ae-bd)x=ce-bf	x=(ce-bf)/(ae-bd)
	//(bd-ae)y=cd-af	y=(cd-af)/(bd-ae)
	double A=b.scn-a.scn,B=a.fst-b.fst;
	double C=a.scn*B+a.fst*A;
	double D=d.scn-c.scn,E=c.fst-d.fst;
	double F=c.scn*E+c.fst*D;
	if(A*E==B*D)	return mp(-1000,-1000);
	return mp((C*E-B*F)/(A*E-B*D),(C*D-A*F)/(B*D-A*E));
}
int main(){
	while(true){
		int n;	cin>>n;
		if(n==0)	break;
		vector<pdd> a(n),b(n);
		for(int i=0;i<n;i++)	cin>>a[i].fst>>a[i].scn>>b[i].fst>>b[i].scn;
		int ret=1;
		for(int i=0;i<n;i++){
			set<pdd> plist;
			for(int j=i-1;j>=0;j--){
				pdd newP=findPoint(a[i],b[i],a[j],b[j]);
				if(fabs(newP.fst)>=100.0||fabs(newP.scn)>=100.0)	continue;
				plist.insert(newP);
			}
			ret+=1+plist.size();
		}
		cout<<ret<<endl;
	}
	return 0;
}
