#include<iostream>

using namespace std;

int n,num;
string ps,maxps;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ps;
		if(ps.size()>maxps.size() || (ps.size()>=maxps.size() && ps>maxps))
		{
			maxps=ps;
			num=i;
		}
	}
	cout<<num<<endl<<maxps<<endl;
	return 0;
}
