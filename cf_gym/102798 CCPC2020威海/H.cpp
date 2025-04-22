#include<bits/stdc++.h>

using namespace std;


int read() {
    int x; scanf("%d",&x); return x;
}

int p[200003],grp[100003];
set<int> st[200003];
int n,m,s;

void work() {
    n=read(); m=read(); s=read();
    while(s--) {
        int t=read(),x=read(),y=read();
        if(t==1) {
            p[x]-=grp[y];
            st[x].insert(y);
        } else if(t==2) {
            p[x]+=grp[y];
            st[x].erase(y);
        } else if(t==3) {
            grp[y]++; p[x]--;
        }
    }
    for(int i=1;i<=m;i++) {
        for(auto x : st[i]) {
            p[i]+=grp[x];
        }
        printf("%d\n",p[i]);
    }
}

signed main() {
    int T=1; //read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}