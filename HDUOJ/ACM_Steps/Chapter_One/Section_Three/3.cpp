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

int n;
struct jian
{
    int a,b;
}jx[53];

void work()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        jx[i].a=read();
        jx[i].b=read();
    }
    sort(jx+1,jx+1+n,[](jian a,jian b){return a.a<b.a;});
    for(int a,b,i=1;i<=n;i++)
    {
        a=jx[i].a;b=jx[i].b;
        for(int j=1;j<=b;j++)
        {
            for(int i=1;i<=a;i++)
        {
            if(i==1)cout<<">+";
            else if(i==a)cout<<"+>"<<endl;
            else cout<<'-';
        }
        }
        cout<<endl;
    }
    return;
}

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
