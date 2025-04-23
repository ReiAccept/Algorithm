#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m,tmp,ans;

vector<int> zd;

int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		if(find(zd.begin(),zd.end(),tmp)==zd.end())
		{
			zd.push_back(tmp);
			ans++;
		}
		
		if(zd.size()>m)
			zd.erase(zd.begin());
	}
	cout<<ans<<endl;
	return 0;
}
