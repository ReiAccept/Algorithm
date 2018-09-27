#include<cstdio>
#include<iostream>

using namespace std;

int n,l,r;
int d[200003];
long long sumL,sumR;
long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	l=1,r=n;
	sumL+=d[1];
	sumR+=d[n];
	while(l<r)
	{
		if(sumL<sumR)
		{
			l++;
			sumL+=d[l];
		}
		if(sumL>sumR)
		{
			r--;
			sumR+=d[r];
		}
		if(sumL==sumR)
		{
			ans=sumL;
			l++;
			r--;
			sumL+=d[l];
			sumR+=d[r];
		}
	}
	cout<<ans<<endl;
	return 0;
}
