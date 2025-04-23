#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n<=4)
		{
			printf("%lld\n",n);
		}
		else 
		{
			int x=n-4,xx;
			if(x%6==0)xx=x/6;
			else xx=x/6+1;
			printf("%lld\n",n-xx);
		}
	}
	return 0;
}

