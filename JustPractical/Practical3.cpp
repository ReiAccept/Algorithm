#include<bits/stdc++.h>
#define int long long

using namespace std;

int read()
{
    int s=0,w=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
    while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
    return s*w;
}

const int N=1e5+3;

int p;
struct Node{
    int v,lza,lzm=1;
    void operator *= (const int k){
        v=(v*k)%p;lzm=(lzm*k)%p;lza=(lza*k)%p;
    }
} t[N<<2];
int a[N];

void pushup(int rt)
{
    int rx=rt<<1;
    t[rt].v=(t[rx].v+t[rx|1].v)%p;
}

void build(int rt,int l,int r)
{
    if(l==r) t[rt].v=a[l]%p;
    else{
        int m=(l+r)>>1,rx=rt<<1;
        build(rx,l,m); build(rx|1,m+1,r);
        pushup(rt);
    }
}

void pushdown(int rt,int l,int r)
{
    int m=(l+r)>>1,rx=rt<<1;
    t[rx].v=(t[rx].v*t[rt].lzm+t[rt].lza*(m-l+1))%p;
    t[rx|1].v=(t[rx|1].v*t[rt].lzm+t[rt].lza*(r-m))%p;

    t[rx].lzm=(t[rx].lzm*t[rt].lzm)%p;
    t[rx|1].lzm=(t[rx|1].lzm*t[rt].lzm)%p;

    t[rx].lza=(t[rx].lza*t[rt].lzm+t[rt].lza)%p;
    t[rx|1].lza=(t[rx|1].lza*t[rt].lzm+t[rt].lza)%p;
    
    t[rt].lzm=1,t[rt].lza=0;
}

void up1(int rt,int nowl,int nowr,int l,int r,int k)//mul
{
    if(r<nowl || l>nowr) return;
    if(l<=nowl && nowr<=r) return t[rt]*=k;
    pushdown(rt,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=rt<<1;
    up1(rx,nowl,m,l,r,k); up1(rx|1,m+1,nowr,l,r,k);
    pushup(rt);
}

void up2(int rt,int nowl,int nowr,int l,int r,int k)
{
    if(r<nowl || l>nowr)return ;
    if(l<=nowl && nowr<=r)
    {
        t[rt].v=(t[rt].v+k*(nowr-nowl+1))%p;
        t[rt].lza=(t[rt].lza+k)%p;
        return;
    }
    pushdown(rt,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=rt<<1;
    up2(rx,nowl,m,l,r,k); up2(rx|1,m+1,nowr,l,r,k);
    pushup(rt);
}

int query(int rt,int nowl,int nowr,int l,int r)
{
    if(r<nowl || nowr<l) return 0;
    if(l<=nowl && nowr<=r) return t[rt].v;
    pushdown(rt,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=rt<<1;
    return (query(rx,nowl,m,l,r)+query(rx|1,m+1,nowr,l,r))%p;
}

signed main()
{
    int n=read(),m=read();p=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op=read(),x=read(),y=read();
        if(op==1) up1(1,1,n,x,y,read());
        else if(op==2) up2(1,1,n,x,y,read());
        else cout<<query(1,1,n,x,y)<<endl;
    }
    return 0;
}
