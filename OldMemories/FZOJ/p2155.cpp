#include<cstdio>

using namespace std;

int ans;
int a,c1,c5,c10,c50,c100,c500;

int main()
{
	scanf("%d%d%d%d%d%d",&c1,&c5,&c10,&c50,&c100,&c500);
	scanf("%d",&a);
	while(a)
	{
		ans++;
		if(a>=500 && c500)
		{
			c500--;
			a-=500;
		}
		else if(a>=100 && c100)
		{
			c100--;
			a-=100;
		}
		else if(a>=50 && c50)
		{
			c50--;
			a-=50;
		}
		else if(a>=10 && c10)
		{
			c10--;
			a-=10;
		}
		else if(a>=5 && c5)
		{
			c5--;
			a-=5;
		}
		else if(a>=1 && c1)
		{
			c1--;
			a-=1;
		}
		else
			ans--;
	}
	printf("%d",ans);
	return 0;
}
