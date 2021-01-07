#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

double a, b, c, x1, x2, x3, p1, p2, p3;

double fun(double x)
{ 
    return (1.0/3)*a*(x-x1)*(x-x1)*(x-x1)+p1*x;
}

void work()
{
    scanf("%lf %lf %lf %lf %lf %lf",&x1, &p1, &x2, &p2, &x3, &p3);
    a=(p2-p1)/((x2-x1)*(x2-x1)),b=(p2+p3)*(x3-x2)/2.0;
    c=fun(x3)-fun(x2)-b;
    printf("%.2lf\n",c);
    return;
}
//真就手动微积分。。。。Fuck
signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
