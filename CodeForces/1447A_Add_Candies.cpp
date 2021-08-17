#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n;

void work()
{
    n=read();
    printf("%d\n",n);
    for(int i=1;i<=n;i++) printf("%d ",i);
    printf("\n");
    return;
}

signed main()
{
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
/*
每一次的操作，可以看成将选择的数减去j（与，“每次选一个数，除它以外所有数都加j” 的效果相同），因为要操作的数是1到n，所以我们按顺序选，第一次操作选1，让1减去1，第二次操作选2，以此类推即可
*/
