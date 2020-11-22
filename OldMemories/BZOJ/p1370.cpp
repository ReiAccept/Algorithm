//OOP(Fake) Disjoint Set Union
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class BCJ
{
	private:
		vector<int> fa;
	public:
		BCJ(int n)
		{
			for(int i=0;i<=n;i++)
				fa.push_back(i);
		}
		int find(int x)
		{
			if(x!=fa[x])
				fa[x]=find(fa[x]);
			return fa[x];
		}
		void mix(int x,int y)
		{
			fa[find(x)]=find(y);
		}
};

int n,m,ans;
int a[2003];

int main()
{
	scanf("%d%d",&n,&m);
	BCJ bcj(2*n);
	for(int i=1;i<=m;i++)
	{
		char ch;
		scanf(" %c",&ch);
		int x,y;
		scanf("%d%d",&x,&y);
		if(ch=='F')
			bcj.mix(x,y);
		else
		{
			bcj.mix(x,y+n);
			bcj.mix(y,x+n);
		}
	}
	for(int i=1;i<=n;i++)
		a[i]=bcj.find(i);	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i-1])
			ans++;		
	printf("%d",ans);
	return 0;
}
