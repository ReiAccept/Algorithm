#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[55];
int main()
{
    cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		bool flag=false;
		for(int i=1;i<n;i++)if(a[i+1]-a[i]>1)flag=true;
		if(!flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
