#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
    int N;
    int Case = 1;
    while (cin >> N)
	{
        int a[20];
        for(int i = 0;i < N;i++)
            cin >> a[i];
        long long maxn = 0;
        long long ans = 1;
        for(int i = 0;i < N;i++)
            for(int j = i;j < N;j++)
			{
                ans = 1;
                for(int k = i;k <= j;k++)
                    ans *= a[k];
                maxn = max (maxn,ans);
			}
        printf("Case #%d: The maximum product is %lld.\n\n",Case++,maxn);
    }
}
// I do not know why the code RE under it.
// What the fuck!!! If have zero,the code under ot not work.
/*
#include<cstdio>
#include<iostream>

using namespace std;

int n,round;
int s[20];
long long maxn;
long long cj[20];

int main()
{
	cj[0]=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			if(i==1)
				cj[i]=s[i];
			else
				cj[i]=cj[i-1]*s[i];
		}
		maxn=0;
		for(int i=0;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(cj[j]/cj[i]>maxn)
					maxn=cj[j]/cj[i];
			}
		printf("Case #%d: The maximum product is %lld.\n",++round,maxn);
	}
	return 0;
}
*/

