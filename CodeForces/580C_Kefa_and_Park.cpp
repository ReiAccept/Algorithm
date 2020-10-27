#include <bits/stdc++.h>
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,m,ans,tot;
int a[100003],head[200010];
struct{int nxt,to;}e[200010];

void dfs(int x,int fa,int val,bool flag=true){
    for(int i=head[x];i;i=e[i].nxt){
        if(fa==e[i].to) continue;
        flag=false;
        if(a[e[i].to]+val>m)continue;
        if(a[e[i].to])dfs(e[i].to,x,a[e[i].to]+val);
        else dfs(e[i].to,x,0);
    }
    if(flag) ans++;
}

void add(int x,int y){//x->y的边
    e[++tot].to=y;//到y节点
    e[tot].nxt=head[x];//当前的head[x]即为接在后面的边
    head[x]=tot;//head 头部,tot指向第几个条边
}

void work()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int u,v,i=1;i<n;i++){
        u=read();v=read();
        add(u,v);add(v,u);
    }
    dfs(1,0,a[1]);
    cout<<ans<<endl;
    return; 
}

signed main()
{
    int Case = 1;//read();
	while(Case--) work();
    return 0;
}
