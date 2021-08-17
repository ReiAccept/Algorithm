#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,k,cnt;
int a[103];
bool v[103];

void work()
{
    n=read();k=read();cnt=0;
    memset(v,0,sizeof(v));
    for(int i=1;i<=n;i++) 
    {
        a[i]=read();
        if(!v[a[i]])
        {
            v[a[i]]=true;
            cnt++;
        }
    }
    if(k==1 && cnt>1) printf("-1\n");
    else if(k==1) printf("1\n");
    else
    {
        int ans=0;
        while(cnt>k)
        {
            cnt-=(k-1);
            ans++;
        }
        printf("%d\n",ans+1);
    }
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
题意：
就是将一个长度为n的a数组分成m个长度为n的数组。而且每个数组最多有k个不同的数。同时使这m个数组的第i位加起来等于a[i]问m最小是多少

思路：
首先考虑什么时候输出-1,当k=1且整个数组有两种不同的数,那么就输出−1那么除此之外k=1时就应该输出1 。
然后考虑普通的,我们先统计所有不同数字的数量。然后每一轮可以减掉k−1,因为我们还需要留一个给不变的(也就是减0 的)用。最后如果数量已经<=k了就输出ans+1,因为再做一次就可以了
 */
