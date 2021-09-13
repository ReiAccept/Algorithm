#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;
const int MOD=998244353;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,ans=1;
int a[203][203],b[203][203];
bitset<203> bit[203];

void insert(bitset<203> x)
{
    for(int i=1;i<=n;i++)
        if (x[i]) 
        {
            if(!bit[i].count()) 
            {
                bit[i]=x;
                break;
            }
            x^=bit[i];
        }
}

void work()
{
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>b[i][j];
    for(int t=1;t<=n;t++)
    {
        for(int i=1;i<=n;i++) bit[i]=0;
        for(int i=1;i<=n;i++)
        {
            bitset<203> x=0;
            for(int j=1;j<=n;j++) x[j]=a[i][j];
            x[i]=x[i]^b[i][t];
            insert(x);
        }
        for(int i=1;i<=n;i++)if(!bit[i].count()) ans=(ans<<1)%MOD;
    }
    cout<<ans<<endl;
    return;
}

signed main()
{
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
