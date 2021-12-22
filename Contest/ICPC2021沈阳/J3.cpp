#include<bits/stdc++.h>

using namespace std;

int a,b;
int ap[5],bp[5];
int ans;

void modfi(int place,int val) {
    ap[place]+=val;
    ap[place]%=10;
}

bool chk(){
    for(int i=1;i<=4;i++) {
        if(ap[i]!=bp[i]) {
            return false;
        }
    }
    return true;
}

void dfs(int dep,int mdd,int lim) {
    printf("dep:%d mdd:%d\n",dep,mdd);
    if(mdd>20 || mdd>lim) {
        return;
    }
    if(dep==5) {
        if(chk()) {
            ans=min(ans,mdd);
        }
        return;
    }
    for(int i=0;i<=10;i++) {
        modfi(dep,i);
        dfs(dep+1,mdd+i,lim);
        modfi(dep,-i);
        modfi(dep,-i);
        dfs(dep+1,mdd+i,lim);
    }
}

void work() {
    scanf("%d%d",&a,&b);
    ans=0x3f3f3f3f;
    for(int i=1;i<=4;i++) {
        ap[i]=a%10; bp[i]=b%10;
    }
    for(int i=1;i<=20;i++) {
        dfs(1,0,i);
    }
    printf("%d\n",ans);
    return;
}

signed main() {
    int T=1;
    scanf("%d",&T);
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}