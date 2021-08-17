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
int v[20];

void dfs(int x,int d,int sum)//x个,最后一个被选的数字d,
{
    //cout<<"sum: "<<sum<<" x: "<<x<<" d: "<<d<<" ";for(int i=0;i<sum;i++)cout<<v[i]<<" "; cout<<endl;
    if(sum>=x)
    {
        //cout<<"DBG2"<<endl;
        for(int i=0;i<sum;i++)cout<<v[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=d+1;i<=n;i++)
    {
        //cout<<"DBG1"<<endl;
        v[sum]=i;
        dfs(x,i,sum+1);
    }
}

void work()
{
    n=read();
    for(int i=0;i<=n;i++) dfs(i,0,0);
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
