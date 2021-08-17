#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

const int N=1000003;
int n,a[N];

void work()
{
    priority_queue<int>q;
    ll ans=0;
    n=read();
    for(int i=1; i<=n; i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) q.push(0);
    for(int i=1; i<=n; i++)
    {
        a[i]-=i;
        q.push(a[i]);
        if(q.top()>a[i])
        {
            ans+=q.top()-a[i];
            q.pop();
            q.push(a[i]);
        }
    }
    printf("%lld\n",ans);
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
先对菜品按时间排序,时间不能重，就是上升序列，按照套路减下标变为求不下降序列。
建一个大根堆，每次看前面的最大值，并移下来，ans就加之间的差。
累加ans就完了
*/
