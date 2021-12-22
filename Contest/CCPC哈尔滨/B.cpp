#include<bits/stdc++.h>

using namespace std;

int read() {
    int x; scanf("%d",&x); return x;
}

const int MAXN=2e5+3;
const int INF=0x3f3f3f3f;

int n;
int a[MAXN];
// int f[MAXN][210];
int b[MAXN][210],s[MAXN][210],ans,c[210],id[MAXN][210];

signed main() {
    n=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    for(int i=1;i<=100;i++) {
        if(a[1]==i)c[i]=1;
        else c[i]=0;
        b[1][i]=0;
    }
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=100;j++) {
            b[i][j]=c[j];
            if(a[i]==j)c[j]=i;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=2;j<=200;j++) {
            int x=j-a[i];
            if(x<=0) {
                s[i][j]=max(s[i][j],s[i-1][j]);
                continue;
            }
            if(b[i][x]==0) {
                s[i][j]=max(s[i][j],s[i-1][j]);
                continue;
            }
            s[i][j]=max(s[b[i][x]-1][j]+1,s[i-1][j]);
        }
    }

    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=100;j++) {
    //         int sum=a[i]+j;
    //         if(b[i][j]==0) {
    //             // s[i][sum]+=s[i-1][sum];
    //             // s[i][sum]=max(s[i][sum],s[i-1][sum]);
    //             continue;
    //         }
    //         // s[b[i][j]][sum]=max(s[i-1][sum]+1,s[b[i][j]][sum]);
    //         // if(s[i-1][sum]+1>s[b[i][j]][sum]) {
    //         //     s[b[i][j]][sum]=s[i-1][sum];
    //         //     id[b[i][j]][sum]=i;
    //         // }
    //         // else if(s[i-1][sum]+1==s[b[i][j]][sum]) {
    //         //     id[b[i][j]][sum]=max(id[b[i][j]][sum],i);
    //         // }
            
    //     }
    // }
    for(int i=2;i<=200;i++) {
        ans=max(ans,s[n][i]);
    }

    // for(int i=2;i<=200;i++)s[0][i]=0;
    // for(int i=1;i<=n;i++) {
    //     for(int j=2;j<=200;j++) {
    //         if(id[i][j]==0) s[i][j]+=s[i-1][j];
    //         else s[i][j]=s[id[i][j]-1][j]+1;
    //         ans=max(ans,s[i][j]);
    //     }
    // }
    // for(int i=1;i<=n;i++) printf("%d%c",s[i][8]," \n"[i==n]);
    // cout<<ans*2<<endl;
    printf("%d\n",ans*2);
    return 0;
}