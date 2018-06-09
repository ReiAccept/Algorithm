#include<iostream>

using namespace std;

struct Node
{
	string xm;
	int qmcj,bjpy,rw;
	bool gb,xb;
	long long ans;
}tmp,best,tmpcpy;

int n;
long long ans;

int main()
{
	best.ans=-99999;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		tmp=tmpcpy;
		cin>>tmp.xm>>tmp.qmcj>>tmp.bjpy;
		string tmps;
		cin>>tmps;
		if(tmps=="Y")
			tmp.gb=true;
		else
			tmp.gb=false;
		cin>>tmps;
		if(tmps=="Y")
			tmp.xb=true;
		else
			tmp.xb=false;
		cin>>tmp.rw;
		if(tmp.qmcj>80 && tmp.rw>=1)
			tmp.ans+=8000;
		if(tmp.qmcj>85 && tmp.bjpy>80)
			tmp.ans+=4000;
		if(tmp.qmcj>90)
			tmp.ans+=2000;
		if(tmp.xb && tmp.qmcj>85)
			tmp.ans+=1000;
		if(tmp.bjpy>80 && tmp.gb)
			tmp.ans+=850;
		if(tmp.ans>best.ans)
			best=tmp;
		ans+=tmp.ans;
	}
	cout<<best.xm<<endl<<best.ans<<endl<<ans<<endl;
	return 0;
}
