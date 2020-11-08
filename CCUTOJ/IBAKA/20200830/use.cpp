#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
using namespace std;

long long S[10000];

void init()
{
	static int top;
	S[0]=4,S[1]=7,top=1;
	for(int i=1;i<9;i++)
		for(int j=(1<<i)-2;j<(1<<i+1)-2;j++)
			S[++top]=S[j]*10+4,S[++top]=S[j]*10+7;
	S[++top]=4444444444ll;
	//for(int i=0;i<=top;i++)
		//printf("%lld\n",S[i]);
}

long long calc(int p)
{
	static long long re;
	re=0;
	if(!p)
		return re;
	for(int i=0;;i++)
	{
		if(S[i]>p)
		{
			if(!i)
				re+=S[i]*p;
			else
				re+=S[i]*(p-S[i-1]);
			return re;
		}
		if(!i)
			re+=S[i]*S[i];
		else
			re+=S[i]*(S[i]-S[i-1]);
	}
}

int main()
{
	static int T;
	init(),scanf("%d",&T);
	for(int Case=1;Case<=T;Case++)
	{
		static int L,R;
		scanf("%d%d",&L,&R);
		printf("%lld\n",calc(R)-calc(L-1));
	}
	return 0;
}