#include<iostream>

using namespace std;

int n,m,ans,a;

int main()
{
    cin>>n>>m;
	while(n--)
    {
		cin>>a;
		ans+=a;
		cout<<ans/m<<" ";
		ans%=m;
	}
	return 0;
}

