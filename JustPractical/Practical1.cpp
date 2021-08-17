#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}

struct Node{
    int v,lza,lzm=1;
} tr[N<<2];
int n,m,p,op;
int a[N];

void push_up(int rt)
{
    int rx=rt<<1;
    tr[rt].v=(tr[rx].v+tr[rx|1].v)%p;
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        //cout<<"RT:"<<rt<<" L:"<<l<<endl;
        tr[rt].v=a[l]%p;
    }
    else
    {
        int m=(l+r)>>1,rx=rt<<1;
        build(rx,l,m);
        build(rx|1,m+1,r);
        push_up(rt);
    }
}

void push_down(int rt,int l,int r)
{
    int m=(l+r)>>1,rx=rt<<1;
    tr[rx].v=(tr[rx].v*tr[rt].lzm+tr[rt].lza*(m-l+1))%p;
    tr[rx|1].v=(tr[rx|1].v*tr[rt].lzm+tr[rt].lza*(r-m))%p;

    tr[rx].lzm=(tr[rx].lzm*tr[rt].lzm)%p;
    tr[rx+1].lzm=(tr[rx+1].lzm*tr[rt].lzm)%p;

    tr[rx].lza=(tr[rx].lza*tr[rt].lzm+tr[rt].lza)%p;
    tr[rx|1].lza=(tr[rx|1].lza*tr[rt].lzm+tr[rt].lza)%p;

    tr[rt].lzm=1,tr[rt].lza=0;
}

void up1(int rt,int nowl,int nowr,int l,int r,int k)//mul
{
    if(r<nowl || nowr<l) return;
    if(l<=nowl && nowr<=r)
    {
        tr[rt].v=(tr[rt].v*k)%p;
        tr[rt].lzm=(tr[rt].lzm*k)%p;
        tr[rt].lza=(tr[rt].lza*k)%p;
        return;
    }
    push_down(rt,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=rt<<1;
    up1(rx,nowl,m,l,r,k);
    up1(rx|1,m+1,nowr,l,r,k);
    tr[rt].v=(tr[rx].v+tr[rx|1].v)%p;
}

void up2(int rt,int nowl,int nowr,int l,int r,int k)//add
{
    if(r<nowl || nowr<l) return;
    if(l<=nowl && nowr<=r)
    {
        tr[rt].v=(tr[rt].v+k*(nowr-nowl+1))%p;
        tr[rt].lza=(tr[rt].lza+k)%p;
        return;
    }
    push_down(rt,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=rt<<1;
    up2(rx,nowl,m,l,r,k);
    up2(rx|1,m+1,nowr,l,r,k);
    tr[rt].v=(tr[rx].v+tr[rx|1].v)%p;
}

int query(int rt,int nowl,int nowr,int l,int r)
{
    if(r<nowl || nowr<l) return 0;
    if(l<=nowl && nowr<=r) return tr[rt].v;
    push_down(rt,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=rt<<1;
    return (query(rx,nowl,m,l,r)+query(rx|1,m+1,nowr,l,r))%p;
}

signed main()
{
    int n=read();int m=read();p=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build(1,1,n);
    while(m--)
    {
        int op=read(),x=read(),y=read();
        if(op==1) up1(1,1,n,x,y,read());
        else if(op==2) up2(1,1,n,x,y,read());
        else cout<<query(1,1,n,x,y)<<endl;
    }
    return 0;
}