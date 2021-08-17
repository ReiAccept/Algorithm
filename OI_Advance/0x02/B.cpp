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

int n,m;
int v[30];

void dfs(int d,int x)//选到d 选了x个数字
{
    if(x>=m)
    {
        for(int i=0;i<m;i++)printf("%lld ",v[i]);
        printf("\n");
        return ;
    }
    for(int i=d+1;i<=n;i++)
    {
        v[x]=i;
        dfs(i,x+1);
    }
}

void work()
{
    n=read();m=read();
    for(int i=1;i<=n-m+1;i++)
    {
        v[0]=i;
        dfs(i,1);
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
