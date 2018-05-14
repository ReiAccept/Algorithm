#include<iostream>
#include<cstdio>

using namespace std;

long long a,b,x,y;

void gcd(long long a,long long b,long long &x,long long &y)
{
	if (b==0)
		x=1;
	else
	{
		gcd(b,a%b,x,y);
		long long t=x;
		x=y;
		y=t-a/b*x;
	}
	return;
}

int main ()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	cin>>a>>b;
	gcd(a,b,x,y);
	while (x < 0)
		x = x + b;
	cout<<x<<endl;
	return 0;
}
/*
ax=1(mod b)
((ax) mod b) == 1
*/
