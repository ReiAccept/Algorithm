#include<bits/stdc++.h>
#define ll long long

using namespace std;

int read()
{
	char c;
	int num,f=1;
	while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;
	num=(int)(c-'0');
	while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');
	return num*f;
}

int pp;
double dp[250];
void work()
{
	pp=read();
	double p=pp/100.0;
	memset(dp,0,sizeof(dp));
	dp[200]=1.0/p;
	for(int i=199;i>=4;i--)
	{
		double q=i/200.0;
		dp[i]=1+p*(1-q)*dp[min(i+4,200)]+(1-p)*dp[min(i+3,200)];
	}
	return;
}

signed main()
{
	int T=read();
	for(int Case=1;Case<=T;Case++)
	{
		work();
		printf("Case %d: %.10lf\n",Case,dp[4]);
	}
	return 0;
}

