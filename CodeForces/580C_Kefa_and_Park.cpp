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

void dfs(int x,int fa,int val){
    
}

void work()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int u,v,i=1;i<n;i++){

    }
    dfs(1,0,0);
    cout<<ans<<endl;
    return; 
}

signed main()
{
    int Case = 1;//read();
	while(Case--) work();
    return 0;
}
