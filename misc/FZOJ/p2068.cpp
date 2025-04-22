#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
	int l,r;
}a[200003];

int n,ans=1;

bool cmp(Node a,Node b)
{
	return a.r<b.r;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,w;
		cin>>x>>w;
		a[i].l=x-w;
		a[i].r=x+w;
	}
	sort(a+1,a+n+1,cmp);
	int zdt=a[1].r;
	for(int i=2;i<=n;i++)
		if (a[i].l>=zdt)
		{
			ans++;
			zdt=a[i].r;
		}
	cout<<ans<<endl;
	return 0;
}
/*
开始的时候想暴力丢上去交个O(N^2)的算法(其实就是裸暴力),以为T1是水题.....还好看了数据范围,优化处理一下有边相连的2个点的要求是abs(xi-xj)>=wi+wj,如果i和j有边,xi-wi到xi+wi和xj-wj到xj+wj这两没有重合部分,把每个点都扩成一段区间,最多的不重合区间数就是最大团的点数,互不重合就代表了两两之间有边
