//和1445C是同一题
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int p,q;
int pr[N],vis[N];

void PRIM(int lim,int cnt=0){//筛法板子
    for(int i=2;i<=lim;i++){
        if(!vis[i]){
            vis[i]=1;pr[++cnt]=i;
            for(int j=i;j<=lim/i;j++) vis[i*j]=1;
        }   
    }
}

void work()
{
    p=read();q=read();
    if(p%q){cout<<p<<endl;return;}
    return;
}

signed main()
{
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
//https://www.cnblogs.com/acceptedzhs/p/13912693.html
