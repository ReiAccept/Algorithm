#include<cstdio>
#include<algorithm>

using namespace std;

int n,a[2003],b[2003];

int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
   for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if((a[i]!=a[j])&&(b[i]!=b[j]))
			{
				printf("%d\n",abs(a[i]-a[j])*abs(b[i]-b[j]));
				return 0;
			}
   printf("-1\n");
   return 0;
}
