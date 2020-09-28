#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,l,maxd;
int a[1003];

void Solve()
{
    n=qrd();l=qrd();
    for(int i=1;i<=n;i++) a[i]=qrd();
    sort(a+1,a+1+n);
    for(int i=1;i<=n-1;i++) maxd=max(maxd,abs(a[i+1]-a[i]));
    if((double)maxd/2.0<a[1]-0 || (double)maxd/2.0<l-a[n]) printf("%.10lf\n",(double)max(l-a[n],a[1]-0));
    else printf("%.10lf\n",(double)maxd/2.0);
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
//⼀个⻓为L的街道左端点是0，右端点是L上有n个相同的灯，第i个灯放置的位置是a[i]问灯的半径⾄少要是多少，才能使得整个街道都有灯光。
