#include <bits/stdc++.h>
#define int long long
#define pt(x) cout << x << endl;
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read()
{
    char c;
    int num, f = 1;
    while(c = getchar(),!isdigit(c)) if(c == '-') f = -1;
    num = c - '0';
    while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
    return f * num;
}
int a,b,c,d,n;

int gx(int x)
{
    int sum=0;
    while(x)
    {
        sum+=(x%10);
        x/=10;
    }
    return sum;
}

int calc(int x)
{
    int g=gx(x);
    return a*x*x*g+b*x*x+c*x*g+d*x*g;
}

inline void work()
{
    a=read(); b=read(); c=read(); d=read();
    n=read();
    //if(a>0 && b>0 && c>0 && d>0) printf("%d\n",a+b+c+d);
    //else
    //{
    //}
    int c1=calc(1),cn=calc(n),c21=calc(gx(n+1)/2);
    printf("%lld\n",min(c1,min(cn,c21)));
    return;
}

signed main()
{
    int Case = read();
    while(Case--) work();
    return 0;
}

