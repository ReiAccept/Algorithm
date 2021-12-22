#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

int x,y;
int ax[66],bx[66];

void work(int CASE) {
    x=read(); y=read(); bitset<66> a(x),b(y);
    memset(ax,0,sizeof(ax));
    memset(bx,0,sizeof(bx));
    // for(int i=0;i<=64;i++) {
    //     a[i]=x&1; x>>=1;
    // }
    if(a.count()!=b.count()) {
        printf("Case %lld: -1\n",CASE);
        return;
    }
    // cout<<"A:"<<a<<" B:"<<b<<endl;
    int cnta=0,cntb=0;
    for(int i=0;i<=65;i+=2) {
        if(a[i]==1) ax[cnta++]=i;
        if(b[i]==1) bx[cntb++]=i;
    }
    if(cnta!=cntb) {
        printf("Case %lld: -1\n",CASE);
        return;
    }
    int ans=0;
    for(int i=0;i<=64;i++) ans+=abs(ax[i]-bx[i])/2;
    cnta=0,cntb=0;
    memset(ax,0,sizeof(ax));
    memset(bx,0,sizeof(bx));
    for(int i=1;i<=65;i+=2) {
        if(a[i]==1) ax[cnta++]=i;
        if(b[i]==1) bx[cntb++]=i;
    }
    if(cnta!=cntb) {
        printf("Case %lld: -1\n",CASE);
        return;
    }
    for(int i=0;i<=64;i++) ans+=abs(ax[i]-bx[i])/2;
    // int ans=0;
    // for(int i=0;i<=65;i++) {
    //     ans+=abs(a[i]-b[i]);
    // }
    printf("Case %lld: %lld\n",CASE,ans);
    // printf("%lld\n",ans/2);

}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work(CASE);
    }
    return 0;
}