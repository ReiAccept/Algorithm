#include <cstdio>
#include <algorithm>

using namespace std;

int n,ans;
int f1=1,f2=33;

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int d1=abs(x-f1),d2=abs(x-f2),d=abs(x-y);
		if(d1<d2)
		{
			ans+=d1+d;
			f1=y;
		}
		else if(d1>d2)
		{
			ans+=d2+d;
			f2=y;
		}
		else
		{
			if(f1==f2)
			{
				f1=y;
			}
			else
			{
				if(x < y) 
				{
					if(f1<f2)
						f1=y;
					else
						f2=y;
				}
				else 
				{
					if(f1>f2)
						f1=y;
					else
						f2=y;
				}
			}
			ans+=d1+d;
		}
	}
	printf("%d\n",ans);
	return 0;
}

