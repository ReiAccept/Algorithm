#include<bits/stdc++.h>

#define LL long long
#define MN 100500

using namespace std;

LL c1[MN],c2[MN];
LL n,m;
LL lb(LL x)
{
	return x&-x;
}

void addd(LL pos,LL data)
{
    for(LL i=pos;i<=n;i+=lb(i))
	{
		c1[i]+=data;
		c2[i]+=data*pos;
	}
}

LL gsum(LL pos)
{
    LL ans=0;
	for(LL i=pos;i;i-=lb(i))
		ans+=(pos+1)*c1[i]-c2[i];
	return ans;
}

int main()
{
    cin>>n>>m;
	for(LL i=1,_;i<=n;i++)
	{
		cin>>_;
		addd(i,_);
		addd(i+1,-_);
	}
    for(LL i=1,cz;i<=m;i++)
    {
        LL x,y,k;
        cin>>cz;
		if(cz==1)
		{
			cin>>x>>y>>k;
			addd(x,k);
			addd(y+1,-k);
		}
        if(cz==2)
		{
			cin>>x>>y;
			cout<<gsum(y)-gsum(x-1)<<endl;
		}
    }
}

