#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define ll long long
//#define int long long
//#define int __int128
//#define int __uint128_t
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar(x%10+'0');}

int n,m,cnt,ans,v[100001];
string str;

struct edge//前向星板
{
    int to,next;
}e[100010];
int tot,g[100001];

void add(int a,int b)
{
    tot++;
    e[tot].next=g[a];
    e[tot].to=b;
    g[a]=tot;
}

void INIT()
{
    cnt=tot=ans=0;
    memset(g,0,sizeof(g));
    memset(v,0,sizeof(v));
}

void dfs(int x)
{
    for(int i=g[x]; i; i=e[i].next)
    {
        if(v[e[i].to]) dfs(e[i].to);
        else ans++;
    }
}

void work()
{
    map<string,int> id;
    n=read();m=read();
    for(int i=1; i<=n; i++)
    {
        cin>>str;
        string tmp;
        int last=0;
        for(int j=0; j<=(int)str.length(); j++)
        {
            if(j==(int)str.length()||str[j]=='/')
            {
                if(!id[tmp])
                {
                    cnt++;
                    id[tmp]=cnt;
                    add(last,cnt);
                }
                int x=id[tmp];
                last=x;
            }
            tmp+=str[j];
        }
    }
    for(int i=1; i<=m; i++)
    {
        cin>>str;
        string tmp;
        for(int j=0; j<=(int)str.length(); j++)
        {
            if(j==(int)str.length() || str[j]=='/') if(id[tmp]) v[id[tmp]]=1;
            tmp+=str[j];
        }
    }
    dfs(0);
    cout<<ans<<endl;
    return;
}

signed main()
{
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        INIT();
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
