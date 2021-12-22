#include<bits/stdc++.h>

using namespace std;

const int MAXN=110;

int n,deta;
int a[MAXN][MAXN];



void work() {
    cin>>n>>deta;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

signed main() {
    int T=1;
    cin>>T;
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    } 
    return 0;
}