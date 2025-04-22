#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) push_back(x)

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f,MOD=1e9+7;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));} //警告,如非必须(如__int128),请不要使用快写

struct Node
{
    int a,num;
} a[200003];

int n,ans[200003];

void dfs(int l,int r)
{
    if(l>r) return;
    int m=(l+r)>>1;
    a[m].a=l-r-1;
    dfs(l,m-1);
    dfs(m+1,r);
}

void work()
{
    n=read();
    dfs(1,n);
    for(int i=1;i<=n;i++) a[i].num=i;
    sort(a+1,a+n+1,[](Node a,Node b){
            if(a.a==b.a)return a.num<b.num;
            return a.a<b.a;
            });
    for(int i=1;i<=n;i++) ans[a[i].num]=i;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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
