#include<bits/stdc++.h>
using namespace std;
int t,n;
int s1[1010],s2[1010];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		getchar();
		int cntb=0,cntq=0;
		for(int i=1;i<=n;i++)
		{
			char s;
			scanf("%c",&s);
			int x=s-'0';
			s1[i]=x;
		 } 
		 getchar();
		 for(int i=1;i<=n;i++)
		 {
		 	char s;
		 	scanf("%c",&s);
		 	int x=s-'0';
		 	s2[i]=x;
		 	if(x>s1[i])cntb++;
		 	if(x==s1[i])cntq++;
		 }
		 if(cntq==n)
		 {
		 	printf("EQUAL\n");
		 	continue;
		 }
		 int cntr=n-cntb-cntq;
		 if(cntr==cntb)
		 {
		 	printf("EQUAL\n");
		 	continue;
		 }
		 if(cntr>cntb)
		 {
		 	printf("RED\n");
		 	continue;
		 }
		 if(cntb>cntr)
		 {
		 	printf("BLUE\n");
		 	continue;
		 }
	}
	return 0;
}
