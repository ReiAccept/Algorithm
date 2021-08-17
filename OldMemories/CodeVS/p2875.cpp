#include<iostream>
#include<map>

using namespace std;

map<string,bool>ma;
string x;
int n,m;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		ma[x]=1;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		if(ma[x])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
