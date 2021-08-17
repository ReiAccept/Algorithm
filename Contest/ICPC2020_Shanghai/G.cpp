#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5+100;

signed main()
{
	int n;
	scanf("%lld",&n);
	int ans=(n-(n/3))*(n/3)+(n/3)*(n/3-1)/2;
	cout<<ans<<endl;
	return 0;
}

