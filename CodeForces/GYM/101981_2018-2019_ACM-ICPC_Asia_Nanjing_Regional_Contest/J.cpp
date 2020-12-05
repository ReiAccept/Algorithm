#include<bits/extc++.h>
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;
const int maxn=1e6+10;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int ans,n,m,cnt_prime;
int a[maxn], p[maxn],v[maxn],prime[maxn], vis[maxn];
vector<int> maze[maxn];
 
void primes(int n){
    memset(v, 0, sizeof(v));
    for(int i = 2; i <= n; i++)
    {
        if(!v[i])
        {
            v[i] = i;
            prime[++cnt_prime] = i;
        }
        for(int j = 1; j <= cnt_prime; j++)
        {
            if(prime[j]>v[i] || prime[j]>n/i) break;
            v[i*prime[j]]=prime[j];
        }
    }
}
 
void divide(int n)
{
    m=0;
    for(int i=1;prime[i]<=n/prime[i]; i++)
        if(n%prime[i]==0)
        {
            p[++m]=prime[i];
            while(n%prime[i]==0) n/=prime[i];
        }
    if(n>1) p[++m]=n;
}
 
signed main()
{
    primes(1000000);
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)
    {
        divide(a[i]);
        for(int j=1;j<=m;j++) maze[i].push_back(p[j]);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)maze[i].size();j++)
        {
            int x = maze[i][j];
            ans += 1LL * (i - vis[x]) * (n - i + 1);
            vis[x] = i;
        }
    cout<<ans<<endl;
    return 0;
}
