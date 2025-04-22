#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

void solve(int &a,int &b,int &c) {
    int x=a;
    int t=max((int)1,(b-c+a)/a);
    int z=t*a+c;
    t=max((int)1,(a-b+a)/z);
    int y=t*z+b;
    a=x,b=y;c=z;
}

void work() {
    int a=read(),b=read(),c=read();
    if(a==b && b==c) {
        if(a==0) {
            printf("YES\n1 1 1\n");
            return;
        } else {
            printf("NO\n");
            return;
        }
    }
    if(a>c) {
        solve(a,b,c);
    }
    else if(c>b) {
        solve(c,a,b);
    }
    else if(b>a) {
        solve(b,c,a);
    }
    // int x,y,z,d[3]={0,1,2},f[3],e=max(a,(max(c,b)));
    // while(c!=e || b==c) {
    //     int tmp=c;
    //     c=b;
    //     b=a;
    //     a=tmp;
    //     tmp=d[2];
    //     d[2]=d[1];
    //     d[1]=d[0];
    //     d[0]=tmp;
    // }
    // f[2]=c;
    // f[1]=b+c;
    // f[0]=a+b+c;
    // for(int i=0;i<3;i++) {
    //     if(d[i]==0) {
    //         x=f[i];
    //     } else if(d[i]==1) {
    //         y=f[i];
    //     } else {
    //         z=f[i];
    //     }
    // }
    // printf("YES\n%lld %lld %lld\n",x,y,z);
    printf("YES\n%lld %lld %lld\n",a,b,c);
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        // printf("CASE:%lld\n",CASE);
        work();
    }
    return 0;
}