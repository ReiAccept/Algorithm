#include<vector>
#include<iostream>

using namespace std;

struct xr{
	bool flag;
	string name;
};

bool flag;
int n,m,cur,num;
vector<xr> a;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		xr tmp;
		cin>>tmp.flag>>tmp.name;
		a.push_back(tmp);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>flag>>num;
		if(num!=0)
		{
			if(a[cur].flag!=flag)
				cur=(cur+num)%n;
			else
				cur=(cur-num%n+n)%n;
		}
	}
	cout<<a[cur].name<<endl;
	return 0;
}
