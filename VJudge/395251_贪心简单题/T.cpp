#include<bits/stdc++.h>
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,mini;
int a[100003];

void Solve()
{
    n=qrd();
    for(int i=1;i<=n;i++)
    {
        a[i]=qrd();
        if(a[i]>=0) a[i]=(-a[i])-1;
        if(a[i]<a[mini]) mini=i;
    }
    if(n%2) a[mini]=(-a[mini])-1;
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
//负数的绝对值是比正数大的，所以为了让答案的绝对值最大，我们可以首先让所有的数都变成负数。
//接下来查看这个序列的乘积，如果乘积小于0，那么就把绝对值最大的一个负数变成正数。
