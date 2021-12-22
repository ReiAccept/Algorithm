#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
char s1[MAXN],s[MAXN];
int ans,d[MAXN][30],l;
void work() {
    ans=0;
    // memset(d,0,sizeof(d));
    scanf("%s",s1+1);
    l=strlen(s1+1);
    // cout<<(s1+1)<<endl;
    for(int i=l;i>=1;i--) {
        s[i]=s1[l-i+1];
    } 
    // cout<<(s+1)<<endl;
    for(int i=1;i<=l;i++) {
        for(int j=1;j<=26;j++) {
            char ss='a'+j-1;
            if(s[i]==ss) d[i][j]=i;
            else d[i][j]=d[i-1][j];
        }
    }
    for(int i=l;i>=1;i--) {
        int x=0;
        for(int j=1;j<=26;j++) {
            char ss='a'+j-1;
            if(s[i]==ss)continue;
            x=max(x,d[i][j]);
        }
        if(x==0) ans=max(ans,i-1);
        else ans=max(ans,i+x);
    }
    for(int i=1;i<=l;i++) {
        for(int j=1;j<=26;j++) d[i][j]=0;
    }
    printf("%d",ans);
}
signed main() {
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
        work();
        if(i!=T)printf("\n");
    }
    return 0;
}