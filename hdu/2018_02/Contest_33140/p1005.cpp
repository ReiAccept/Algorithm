#include<cmath>
#include<cstdio>
#include<climits>

using namespace std;

int T,n,m;//m是n开方之后,怕取整问题加上5
int a[20003],s[20003],f[20003][210];

inline void up(int &a,int b){a<b?(a=b):0;}
//我可QTMD三目运算符,每次都得让我写个注释
//这里是指如果a<b的话,那么让a=b否则的话,什么都不做
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		m=(int(sqrt(n*2))+5);
		for(int i=1;i<=m;i++)
			s[i]=s[i-1]+a[i];
		for(int i=1;i<=m;i++)
			f[n+1][i]=0;
		for(int i=n;i;i--)
		{

		}
	}
	return 0;
}
