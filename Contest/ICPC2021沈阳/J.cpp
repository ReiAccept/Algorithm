#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=2000+10;

int read() {
    int x; scanf("%lld",&x); return x;
}

int a,b;
int ap[5],bp[5];

void modfi(int &t,int p,int x) { //修改的 数 位置 值
    for(int i=2;i<=p;i++) {
        x*=10;
    }
    t+=x;
}

int modfilr(int l,int r,int t,int x) {
    for(int i=l;i<=r;i++) {
        modfi(t,i,x);
    }
    return t;
}

int cmpab() {
    for(int i=1;i<=4;i++) {
        if(ap[i]!=bp[i]) {
            return false;
        }
    }
    return true;
}

int ans=0;
void dfs(int lim,int deep,int a,int b) {
    if(deep>lim) return;
    for(int l=1;l<=4;l++) {
        for(int r=1;r<=4;r++) {
            int ta=modfilr(l,r,a,1);
            int tb=modfilr(l,r,a,-1);
            // printf("LIM:%lld DEEP:%lld %lld %lld \n",lim,deep,ta,tb);
            if(ta==b || tb ==b) {
                // return true;
                ans=deep;
            }
            dfs(lim,deep+1,ta,b);
            dfs(lim,deep+1,tb,b);
        }
    }
    // return false;
}

void work() {
    a=read(); b=read();
    for(int i=1;i<=4;i++) {
        ap[i]=a%10; bp[i]=b%10;
        a/=10; b/=10;
    }
    ans=0;
    for(int i=1;i<=17;i++) {
        dfs(i,0,a,b);
        if(ans!=0) {
            printf("%lld\n",i);
            return;
        }
    }
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}