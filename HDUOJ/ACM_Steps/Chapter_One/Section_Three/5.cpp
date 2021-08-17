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
int a[103],b[103];

void work()
{
    while(n=read())
    {
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++)b[i]=read();
        int ax=0,bx=0;
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        for(int i=1;i<=n;i++)
        {
            if(a[i]>b[i])ax+=2;
            else if(a[i]<b[i])bx+=2;
            else ax++,bx++;
        }
        printf("%lld vs %lld\n",ax,bx);
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
