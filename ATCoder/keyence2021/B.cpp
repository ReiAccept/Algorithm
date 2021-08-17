#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define ll long long
#define int long long
//#define int __int128
//#define int __uint128_t
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace _gnu_pbds;

const int INF=0x3f3f3f3f;

int read()
{
	char c;
	int num,f=1;
	while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;
	num=(int)(c-'0');
	while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');
	return num*f;
}

int n,k;
int a[300010];
int b[300010];
int ans;
int minn;
void work()
{
	n=read(); k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[a[i]]++;
	}
	sort(a+1,a+1+n);
	minn=k;
	for(int i=0;i<=a[n]+1;i++)
	{
		int x=b[i];
		if(x>=minn) continue;
		else
		{
			int xx=minn-x;
			ans+=i*xx;
			minn=x;
		}
		if(minn==0) break;
	}
	cout<<ans<<endl;
	return;
}

signed main()
{
	int T=1;//read();
	for(int Case=1;Case<=T;Case++)
	{
		//printf("Case #%d: ",Case);
		work();
	}
	return 0;
}

