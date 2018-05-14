#include<cstdio>

#define INT_MAX 0x3f3f3f3f

using namespace std;

int n,m,ans;
bool flag;
int f[103][103];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				f[i][j]=INT_MAX;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=z;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(f[i][j]>f[i][k]+f[k][j])
					f[i][j]=f[i][k]+f[k][j];
	for(int i=1;i<=n && !flag;i++)
		if(f[1][i]==INT_MAX)
			flag=true;
		else if(f[1][i]>ans)
			ans=f[1][i];
	if(!flag)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
