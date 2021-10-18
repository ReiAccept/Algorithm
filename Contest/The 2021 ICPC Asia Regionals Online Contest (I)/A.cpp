#include<bits/stdc++.h>
#define int long long

using namespace std;

int k,n,res;

int query(int l,int r,int p,int lx,int rx)
{
    if(lx<=l && r<=rx) return t[p];
    int m=(l+r)>>1;
    if(y<=mid) return query(l,mid,p<<1,lx,rx);
    if(x>mid) return query(mid+1,r,p<<1|1,lx,rx);
    return min(query(l,mid,p<<1,lx,rx),query(mid+1,r,p<<1|1,lx,rx));
}

void mod(int l,int r,int p,int lx,int rx)
{
    if(l==r)
    {
        t[p]=rx;
        return ;
    }
    int m=(l+r)>>1;
    if(x<=m) mod(l,mid,p<<1,lx,rx);
    if(x>m) mod(mid+1,r,p<<1|1,lx,rx);
    t[p]=min(t[p<<1],t[p<<1|1]);
}

signed main()
{
    scanf("%lld%lld",&k,&n);
    for(int i=0;i<n;i++)
    {
        int at,pt; scanf("%lld%lld",&at,&pt);
        int l=i%k+1,r=i%k+1;
        if(query(l,k<<1,1,l,r) > at) continue;
        while(l<r)
        {

        }
    }
    return 0;
}
