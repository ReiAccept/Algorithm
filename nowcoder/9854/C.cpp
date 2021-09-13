#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
bool f[200003];
bool flag;

void INIT()
{
    for(int i=2;i<=100009;i++)
        if(!f[i])
        {
            for(int j=i*2;j<=100009;j+=i)
                f[j]=true;
        }
}

void work()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int t=read();
        if(t==1)flag=true;
        for(int j=2;j*j<t;j++)
        {
            if(!(t%j))f[j]=true;
            while(!(t%j))t/=j;
        }
        if(t) f[t]=true;
    }
    if(!flag)
    {
        cout<<1<<endl;
        return;
    }
    for(int i=2;i<=100009;i++)
    {
        if(!f[i])
        {
            cout<<i<<endl;
            return;
        }
    }
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        INIT();
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
