#include<cstdio>

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	if(n<k || k>26 || (k<=1 && n>1))
	{
		printf("-1");
		return 0;
	}
	if(n==1 && k==1)
	{
		printf("a");
		return 0;
	}
	for(int i=1;i<=n-k+2;i++)
	{
		if(i%2) 
			printf("a");
		else 
			printf("b");
	}
	for(int i=1;i<=k-2;i++)
		printf("%c",i+98);
	return 0;
}
/*
题目大意是生成一个字典序最小的字符串,相邻字符不相同,且出现k个不同的字符.
对于k>2的情况,只要在前面不断输出ababab……最后把剩下的字符都输出出来就好。
这样显然是字典序。
然后有一些特判
k>n，直接-1不用考虑
k=1,n=1，只输出一个a
k=1,n>1这个显然-1
k=2，全都是abababab…
*/
