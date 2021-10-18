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
int fa[100003];
bool vis[100003];
priority_queue<pair<int,int> > q;

void INIT()
{
    n=read();
    for(int i=1;i<=n;i++) fa[i]=i;
    while(!q.empty()) q.pop();
    mmst0(vis);
}

int find_root(int x) 
{
    return fa[x]==x?x:fa[x]=find_root(fa[x]);
}
int unionset(int x,int y)
{
    int xx=find_root(x),yy=find_root(y);
    if(xx>yy) swap(xx,yy);
    fa[xx]=yy; 
    return yy;
}

void work()
{
    for(int i=1;i<=n;i++)
    {
        q.push({read(),i});
    }
    while(!q.empty() && q.top().first>1)
    {
        int fi=q.top().first,se=q.top().second;
        q.pop();
        if(fi!=q.top().first) continue;//不能合并了
        if(q.empty()) break;
        int u=q.top().second;
        q.pop();
        int ee=unionset(se,u);
        q.push({fi-1,ee});
    }
    if(q.size()<2)
    {
        printf("NO\n");
        return;
    }
    int ee=q.top().second;
    for(int i=1;i<=n;i++)
    {
        if(find_root(i)==ee) vis[i]=true;
         else vis[i]=false;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++) cout<<vis[i];
    cout<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=read();
    for(int Case=1;Case<=T;Case++)
    {
        printf("Case %lld: ",Case);
        INIT();
        work();
    }
    return 0;
}
