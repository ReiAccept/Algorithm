#include<cstdio>
#include<cstring>

using namespace std;

int n,ans;
int a[10003],f[10003];

bool chk()
{
	for(int i=2;i<=n;i++)
		f[i+1]=a[i]-f[i-1];
	for(int i=1;i<=n;i++)
		if(f[i]!=1 && f[i]!=0)
			return false;
	if(f[n+1])
		return false;
	return true;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=a[1];i++)
	{
		memset(f,0,sizeof(f));
		f[1]=i;
		f[2]=a[1]-i;
		if(chk())
			ans++;
	}
	printf("%d",ans);
	return 0;
}
