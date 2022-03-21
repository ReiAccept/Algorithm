#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int res=0,flag=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*flag;
}
int n;
struct work
{
	int w;
	int t;
	bool operator <(work x2)
	{
		return w>x2.w;
	}
}x[100001];
int c[100001];
ll ans;
inline int lowbit(int a)
{
	return a&(-a);
}
inline void update(int pos,int v)
{
	while(pos<=n)
	{
		c[pos]+=v;
		pos+=lowbit(pos);
	}	
}
inline int sum(int pos)
{
	int res=0;
	while(pos)
	{
		res+=c[pos];
		pos-=lowbit(pos);
	}
	return res;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		x[i].t=min(read(),(int)1e5);
		x[i].w=read();
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;++i)
		if(sum(x[i].t)!=x[i].t)
		{
			int l=1,r=x[i].t,mid,res;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(sum(x[i].t)-sum(mid-1)!=x[i].t-mid+1)
				{
					res=mid;
					l=mid+1;
				}
				else
					r=mid-1;
			}
			update(res,1);
			ans+=x[i].w;
		}
	printf("%lld\n",ans);
    return 0;
}