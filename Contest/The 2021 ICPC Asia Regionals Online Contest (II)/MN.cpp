#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1000;

int a[MAXN],b[MAXN],c[MAXN],sgn[MAXN],pwx[MAXN];

int n,ax,bx,cx;

void optput()
{
    for(int i=1;i<=n;i++) {
        printf("%lld",c[i]);
        printf(" ");
    }
}

void dfs(int cur,int now)
{
    //printf("%lld %lld\n",cur,now);
    if(cur>=n) return;
    if(now==0)
    {
        optput();
        exit(0);
    }
    //for(int i=cur+1;i<n;i++) {
    c[cur]=0;
    dfs(cur+1,now-sgn[cur]*pwx[cur]*c[cur]);
    c[cur]=1;
    dfs(cur+1,now-sgn[cur]*pwx[cur]*c[cur]);
    //}    
}

signed main()
{
    cin>>n;
    for(int i=0;i<=63;i++) pwx[i]=pow(2,i); 
    for(int i=0;i<n;i++) cin>>sgn[i];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) {
        ax=ax+sgn[i]*a[i]*pwx[i];
        bx=bx+sgn[i]*b[i]*pwx[i];
    }
    cx=ax+bx;
    c[0]=1;
    dfs(1,cx-c[0]*pwx[0]*sgn[0]);
    c[0]=0;
    dfs(1,cx-c[0]*pwx[0]*sgn[0]);
    return 0;
}
