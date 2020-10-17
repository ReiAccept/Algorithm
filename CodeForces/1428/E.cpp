#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,k,sum,ans,x,y;
int a[100003],c[100003];
set<pair<int,int>>s;

int read(){
	char c; int num, f = 1;
	while(c = (char)getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = (char)getchar(), isdigit(c)) num = num * 10 + c - '0';
	return num * f;
}



int cal(int v,int t)
{
	int k=v/t,x=v%t;
	return k*k*(t-x)+(k+1)*(k+1)*x;
}

signed main()
{
    n=read();k=read();
    for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		sum+=cal(a[i],1);
		if(a[i]!=1) s.insert(make_pair(cal(a[i],2)-cal(a[i],1),i));
	}
	for(int i=1;i<=k-n;i++)
	{
		x=s.begin()->second;
        y=s.begin()->first;
		s.erase(s.begin());
		c[x]++;
        sum+=y;
		if(c[x]+1!=a[x])s.insert(make_pair(cal(a[x],c[x]+2)-cal(a[x],c[x]+1),x));
	}
	printf("%lld\n",sum);
	return 0;
}

