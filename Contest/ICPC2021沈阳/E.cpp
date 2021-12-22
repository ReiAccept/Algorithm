#include<bits/stdc++.h>

using namespace std;

const int MAXN=200000+10;

int n;
char s[MAXN],ss[]="edgnb";

bool chk(int st) {
    // bool flag=true;
    for(int i=0;i<5;i++) {
        if(s[st+i]!=ss[i]) {
            return false;
        }
    }
    return true;
}

signed main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(s[i]=='e') {
            if(chk(i)) {
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}