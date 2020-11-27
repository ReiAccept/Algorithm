#include <bits/stdc++.h>
#define ll long long
//#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n;
int a[203],d[203][203],f[203][203],sum[203],ansd=INF,ansf;

void work()
{
    n=read();
    for(int i=1;i<=n;i++) a[n+i]=a[i]=read();
    for(int i=1;i<=n<<1;i++) sum[i]=sum[i-1]+a[i];
    for(int len=1;len<n;len++)
    {
        for(int i=1,j=len+1;i<(n<<1) && j<(n<<1);i++,j++)
        {
            d[i][j]=INF;
            for(int k=i;k<j;k++)
            {
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+(sum[j]-sum[i-1]));
                d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]+(sum[j]-sum[i-1]));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ansf=ansf>f[i][i+n-1]?ansf:f[i][i+n-1];
        ansd=ansd<d[i][i+n-1]?ansd:d[i][i+n-1];
    }
    printf("%d\n%d\n",ansd,ansf);
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
