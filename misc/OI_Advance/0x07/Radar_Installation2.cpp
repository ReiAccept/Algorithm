#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*w;
}
struct Node{
	double l,r;
};
const int SIZE = 1010;
const double eps = 1e-6,INF = 1e10;

int n,r;
Node s[SIZE];

bool cmp(Node a, Node b)
{
	return a.r < b.r;
}

int main()
{
	while(n=read(),r=read())
	{
		if(!n && !r) break;
		bool suc = true;
		for(int i = 0; i < n && suc; ++ i)
		{
			int x = read(),y = read();
			if(y > r) suc = false ;
			double len = sqrt(r * r - y * y);
			s[i].l = x - len,s[i].r = x + len;
		}
		if(!suc) puts("-1");
		else 
		{
			sort(s,s+n,cmp);
			int ans = 0;
			double last = -INF;
			for(int i = 0; i < n; ++ i)
			{
				if(s[i].l > last + eps)
				{
					ans ++ ;
					last = s[i].r;
				}
			}
			printf("%d\n",ans);
		}
		break;//break this loop for AcWing 
	}
	
	return 0;
}
