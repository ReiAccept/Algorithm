#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e5+3;

bool isprime(int x) {
    if(x==1) return false;
    if(x==2 || x==3) return true;
    for(int i=2;i<=sqrt(x);i++) {
        if(x%i==0) return false;
    }
    return true;
}

int n,sum;
bool flag;
int a[MAXN];
int prime[MAXN],cnt;
bool st[MAXN];

void work(int CASE) {
    n=read(),sum=0,flag=true;
    for(int i=1;i<=n;i++) {
        a[i]=read();
        sum+=a[i];
    }
    if(n==1 && a[1]!=1) {
        printf("Case %lld: 0\n",CASE);
        return;
    }
    int d=a[1];
    for(int i=2;i<=n;i++) {
        d=__gcd(d,a[i]);
    }
    if(d>1) {
        printf("Case %lld: 0\n",CASE);
        return;
    }
    if(sum==n) {
        printf("Case %lld: 1\n",CASE);
        return;
    }
    sort(a+1,a+1+n);
    // for(int i=2;i<=n;i++) {
    //     if(a[i]==a[i-1]+1) {
    //         printf("Case %lld: -1\n",CASE);
    //     }
    //     // if(a[i] % a[1]) {
    //     //     flag=false;
    //     // }
    // }
    // if(flag) {
    //     printf("Case %lld: 0\n",CASE);
    //     return;
    // }
    d=0;
    for(int i=2;i<=n;i++) {
        d=__gcd(d,a[i]-a[i-1]);
    }
    // if(d>1) {
    //     printf("Case %lld: 0\n",CASE);
    //     return;
    // }
    if(d==1) {
        printf("Case %lld: -1\n",CASE);
        return;
    }
    // if(!prime[d]) {
    if(isprime(d)) {
        if(a[1]<=d) {
            printf("Case %lld: %lld\n",CASE,d-a[1]);
            return;
        }
        printf("Case %lld: %lld\n",CASE,d-a[1]%d);
        return;
    }
    // int ans=0;
    // ans=(a[1]/d+1)*d-a[1];
    // printf("Case %lld: %lld\n",CASE,ans);
    for(int i=1;true;i++) {
        if(__gcd(d,a[1]+i)>1) {
            printf("Case %lld: %lld\n",CASE,i);
            return;
        }
    }
}

signed main() {
    for(int i=2;i<=MAXN;i++) {
        if(!st[i]) prime[cnt++]=i;
        for(int j=0;prime[j]<=MAXN/i;j++) {
            st[prime[j]*i]=true;
            if(i%prime[j]==0) {
                break;
            }
        }
    }
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work(CASE);
    }
    return 0;
}