#include<bits/stdc++.h>

using namespace std;

int ans;
int a[5],b[5],d[5];

void work() {
    string ta,tb;
    cin>>ta>>tb;
    for(int i=0;i<4;i++) {
        a[i+1]=ta[i]-'0';
        b[i+1]=tb[i]-'0';
    }
    for(int i=1;i<=4;i++) {
        d[i]=a[i]-b[i];
    }
    for(int i=4;i>=1;i--) {
        d[i]-=d[i-1];
    }
    for(int i=1;i<=4;i++) {
        d[i]=(d[i]%10 + 10)%10;
    }
    ans=20;
    for(int j=0;j<16;j++) {
        int ut=0,dt=0;
        for(int i=1;i<=4;i++){
                if(j&(1<<(i-1))) {
                    ut+=(10-d[i])%10;
                } else {
                    dt+=d[i];
                }
            }
        ans=min(ans,max(ut,dt));
    }
    printf("%d\n",ans);
}

signed main() {
    int T; cin>>T; //scanf("%d",&T);
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}