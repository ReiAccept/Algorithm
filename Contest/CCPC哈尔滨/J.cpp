#include<bits/stdc++.h>

using namespace std;

int read() {
    int x; scanf("%d",&x); return x;
}

const int INF=0x3f3f3f3f;

int n,m;
int mat[1003][1003];
int minline[1003],minrow[1003];

signed main() {
    n=read(); m=read();
    for(int i=1;i<=n;i++) {
        int minl=INF;
        for(int j=1;j<=m;j++) {
            mat[i][j]=read();
            minl=min(minl,mat[i][j]);
        }
        minline[i]=minl;
    }
    for(int i=1;i<=m;i++) {
        int minr=INF;
        for(int j=1;j<=n;j++) {
            minr=min(mat[j][i],minr);
        }
        minrow[i]=minr;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(mat[i][j]==min(minline[i],minrow[j])) {
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}