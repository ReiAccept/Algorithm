#include<cstdio>

long long f[36];int n;

int main()
{
	scanf("%d",&n);
	f[0]=1,f[1]=1;
	for(int i=2;i<=n;++i)
		for(int j=0;j<=i-1;++j)
			f[i]+=f[j]*f[i-1-j];
	printf("%lld",f[n]);
	return 0;
}
