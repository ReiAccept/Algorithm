#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e5+3;

int n,cnt,sum;
int a[MAXN];
vector<int> low;

void work(int CASE) {
    n=read(),cnt=0,sum=0;
    low.clear();
    // memset(vix,0,sizeof(vix)); 
    // vix[1]=vix[n]=true; //左右端点特判
    for(int i=1;i<=n;i++) {
        a[i]=read();
        sum+=a[i];
    }
    a[0]=a[n+1]=-1;
    for(int i=2;i<n;i++) {
        if(a[i+1]> a[i] && a[i-1]>a[i]) {
            low.emplace_back(i);
        }
    }
    for(int i=1;i<n && a[i]<a[i+1];i++) {
        a[i]=a[i-1]+1;
    }
    for(int i=n;i>1 && a[i]<a[i-1];i--) {
        a[i]=a[i+1]+1;
    }
    for(auto x:low) {
        a[x]=0;
        for(int i=x-1;i>1 && a[i]<a[i-1];i--) { //LEFT
            a[i]=a[i+1]+1;
        }
        for(int i=x+1;i<n && a[i]<a[i+1];i++) { //RIGHT
            a[i]=a[i-1]+1;
        }
    }
    for(int i=1;i<=n;i++) {
        if(a[i]>a[i+1] && a[i]>a[i-1]) {
            a[i]=max(a[i+1],a[i-1])+1;
        }
    }
    for(int i=1;i<=n;i++) {
        sum-=a[i];
    }
    // for(int i=1;i<=n;i++) {
    //     printf("%lld%c",a[i]," \n"[i==n]);
    // }
    // printf("SUM:%lld\n",sum);
    if(sum%2) {
        printf("Case %lld: Alice\n",CASE);
    } else {
        printf("Case %lld: Bob\n",CASE);
    }
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work(CASE);
    }
    return 0;
}