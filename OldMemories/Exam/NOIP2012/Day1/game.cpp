#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

struct hand
{
	int a,b,val;
} dc[1003];

int n;
long long atmp=1,res;
long long gold[1003];

bool cmp(hand a,hand b)
{
	return a.val<b.val;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		scanf("%d%d",&dc[i].a,&dc[i].b);
		dc[i].val=dc[i].a*dc[i].b;
	}
	sort(dc+1,dc+n+1,cmp);
	atmp=1;
	for(int i=1;i<=n;i++)
	{
		atmp=atmp*dc[i-1].a;
		gold[i]=atmp/dc[i].b;
	}
	for(int i=1;i<=n;i++)
		res=max(res,gold[i]);
	cout<<res<<endl;
	return 0;
}
