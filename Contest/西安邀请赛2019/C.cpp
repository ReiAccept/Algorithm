#include<bits/stdc++.h>
//#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int N=(int)1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct Point
{   //声明结构体类型
    double x;      // 该点的x坐标
    double y;      // 该点的y坐标
}C,P,Q1,Q2,U;
// C是圆心的坐标 P是点的坐标 Q1,Q2是切点坐标 U是点到圆心的单位向量坐标

double getdis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
} 

void work()
{
    double r=0; // 圆的半径
    cin>>C.x>>C.y>>r>>P.x>>P.y;
    double r14=r*2*acos(-1)/4;
    if(P.x<=C.x-r)
    {
        Point rx; rx.x=C.x-r; rx.y=C.y;
        printf("%.4lf\n",getdis(P,rx)+r14);
    }
    else if(P.x>=C.x+r)
    {
        Point rx; rx.x=C.x+r; rx.y=C.y;
        printf("%.4lf\n",getdis(P,rx)+r14);
    }
    else
    {
        double dis=getdis(P,C); // 圆心r 到p 点的距离
        double angle=abs(P.x-C.x)/dis; // 切线与点心连线的夹角
        double a=r/dis;
        if(P.x==C.x)
        {
            double ans=0.5*acos(-1)-acos(r/dis);
            ans+=0.5*acos(-1);
            ans*=r;
            ans+=sqrt(dis*dis-r*r);
            printf("%.4lf\n",ans);
        }
        else
        {
            double ans=acos(angle)-acos(a);
            ans+=0.5*acos(-1);
            ans*=r;
            ans+=sqrt(dis*dis-r*r);
            printf("%.4lf\n",ans);
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;cin>>T;
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}