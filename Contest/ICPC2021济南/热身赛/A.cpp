#include<bits/stdc++.h>
// #define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

int n;
int sgn[64],va[64],vb[64];

void work() {
    // n=read();
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>sgn[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>va[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>vb[i];
    }
    int p=0;
    for(int i=1;i<=n;i++) {
        p=p*sgn[i];
        int k=va[i]+vb[i]+p;
        if(k==2) {
            p=1; 
            cout<<0;
        }else if(k==1){
            p=0; 
            cout<<1;
        }else if(k==-1){
            p=-1;
            cout<<1;
        }else if(k==0){
            p=0; 
            cout<<0;
        }else if(k==3){
            p=1; 
            cout<<1;
        }
        p=p*sgn[i];
        if(i!=n) {
            printf(" ");
        }
    }
     return;
}

signed main() {
    work();
    return 0;
}

/*
k  -1   0   0   1   1   2   2   3
a   0   1   0   0   1   1   0   1
b   0   0   1   0   1   0   1   1
s  -1  -1  -1   1  -1   1   1   1
*/