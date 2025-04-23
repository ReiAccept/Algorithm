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
struct wood
{
    int l,w;
}a[5003];

bool vis[5003];

void work()
{
    n=read();
    mmst0(vis);
    for(int i=1;i<=n;i++)
    {
        a[i].l=read();
        a[i].w=read();
    }
    sort(a+1,a+1+n,[](wood a,wood b){
        if(a.l!=b.l) return a.l<b.l;
        else return a.w<b.w;
        });
    int ans=0,sum=0;
    while(sum<n)
    {
        int tl=0,tw=0;
        ans++;
        for(int i=1;i<=n;i++)
        {
            if(a[i].l>=tl && a[i].w>=tw && (!vis[i]))
            {
                vis[i]=true;
                sum++;
                tl=a[i].l;
                tw=a[i].w;
            }
        }
    }
    cout<<ans<<endl;
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
