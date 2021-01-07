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

//int a[15]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};//其实可以打表过
int n;
int vis[16];

void work()
{
    while(n=read())
    {
        if(vis[n])
        {
            cout<<vis[n]<<endl;
            continue;
        }
        for(int ans=n+1;!vis[n];ans++)
        {
            int sum=n*2;
            for(int j=ans;;j+=ans-1)
            {
                if(j>sum)
                {
                    j= j%sum ? j%sum : sum;
                }
                if(j<=n) break;
                else sum--;
                if(sum==n)
                {
                    vis[n]=ans;
                    cout<<vis[n]<<endl;
                    break;
                }
            }
        }
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
