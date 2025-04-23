#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
struct Node{
    int val,add,mul=1;
} t[400003];

int p;
int a[100003];

void build_t(int root,int l,int r)
{
    t[root].mul=1,t[root].add=0;
    if(l==r) t[root].val=a[l]%p;
    else
    {
        int m=(l+r)>>1,rx=root<<1;
        build_t(rx,l,m);
        build_t(rx+1,m+1,r);
        t[root].val=(t[rx].val+t[rx+1].val)%p;
    }
}
void push_down(int root,int l,int r)
{
    int m=(l+r)>>1,rx=root<<1;
    t[rx].val=(t[rx].val*t[root].mul+t[root].add*(m-l+1))%p;
    t[rx+1].val=(t[rx+1].val*t[root].mul+t[root].add*(r-m))%p;//!!!!!!!!!!!!!!!!!!rx+1
    
    t[rx].mul=(t[rx].mul*t[root].mul)%p;
    t[rx+1].mul=(t[rx+1].mul*t[root].mul)%p;

    t[rx].add=(t[rx].add*t[root].mul+t[root].add)%p;
    t[rx+1].add=(t[rx+1].add*t[root].mul+t[root].add)%p;
    
    t[root].mul=1,t[root].add=0;
}

void up1(int root,int nowl,int nowr,int l,int r,ll k)
{
    if(r<nowl || nowr<l) return;
    if(l<=nowl && nowr<=r)
    {
        t[root].val=(t[root].val*k)%p;
        t[root].mul=(t[root].mul*k)%p;
        t[root].add=(t[root].add*k)%p;
        return;
    }
    push_down(root,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=root<<1;
    up1(rx,nowl,m,l,r,k);
    up1(rx+1,m+1,nowr,l,r,k);
    t[root].val=(t[rx].val+t[rx+1].val)%p;
}

void up2(int root,int nowl,int nowr,int l,int r,ll k)
{
    if(r<nowl || nowr<l) return;
    if(l<=nowl && nowr<=r)
    {
        t[root].add=(t[root].add+k)%p;
        t[root].val=(t[root].val+k*(nowr-nowl+1))%p;
        return;
    }
    push_down(root,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=root<<1;
    up2(rx,nowl,m,l,r,k);
    up2(rx+1,m+1,nowr,l,r,k);
    t[root].val=(t[rx].val+t[rx+1].val)%p;
}

ll query(int root,int nowl,int nowr,int l,int r)
{
    if(r<nowl || nowr<l) return 0;
    if(l<=nowl && nowr<=r) return t[root].val;
    push_down(root,nowl,nowr);
    int m=(nowl+nowr)>>1,rx=root<<1;
    return (query(rx,nowl,m,l,r)+query(rx+1,m+1,nowr,l,r))%p; 
}

signed main()
{
    int n=read();int m=read();p=read();
    for(int i=1;i<=n;i++) a[i]=read();
    build_t(1,1,n);
    while(m--)
    {
        int op=read(),x=read(),y=read();
        if(op==1) up1(1,1,n,x,y,read());
        else if(op==2) up2(1,1,n,x,y,read());
        else cout<<query(1,1,n,x,y)<<endl;
    }
    return 0;
}
