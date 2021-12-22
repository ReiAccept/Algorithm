#include<bits/stdc++.h>
#define int long long
using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

int n,x,t,ans;

void work() {
    n=read(); x=read(); t=read();
    ans=2*n*t;
    int d2=ans-2*t; //第二位老人的休息时间
    if(d2>=x) {
        printf("%lld\n",ans*2);
        ans*=2;
    } else {
        int sum1=ans*2+(x-d2); //等待我已经在这边的老人休息完成
        int sum2=ans*2;  //我过到对面去，对面的老人更快的休息完成
        if(ans>=x) sum2+=t;
        else sum2+=t+x-ans;
        printf("%lld\n",min(sum1,sum2));
    }
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}