#include<bits/stdc++.h>
// #define int long long

using namespace std;

int read() {
    int x; scanf("%d",&x); return x;
}

const int MAXN=1e6+3;

int n,cnt;
int a[MAXN];
char s[MAXN];
// vector<int> p;


void work() {
    n=read(); cnt=0;
    // p.clear();
    scanf("%s",s+1);
    // memset(a,0,sizeof(a));
    for(int i=0;i<n+3;i++) {
        a[i]=0;
    }
    for(int i=1;i<=n;i++) {
        if(s[i]=='1') {
            // p.emplace_back(i);
            cnt++;
            a[i]=0;
        } else a[i]=a[i-1]+1;
    }
    for(int i=n;i>=1;i--) {
        if(a[i]!=0 && a[i+1]!=0) {
            a[i]=a[i+1];
        }
    }
    int ans1=0;
    for(int i=1;i<=n;i++) {
        if(s[i]=='1') {
            break;
        } else {
            ans1++;
        }
    }
    int ans2=0;
    for(int i=n;i>=1;i--) {
        if(s[i]=='1') {
            break;
        } else {
            ans2++;
        }
    }
    for(int i=1;i<=n;i++) {
        if(a[i]==0) {
            ans1=max(ans1,a[i-1]);
        }
    }
    // for(int i=1;i<=n;i++) {
    //     printf("%lld%c",a[i]," \n"[i==n]);
    // }
    for(int i=n;i>=1;i--) {
        if(a[i]==0) {
            ans2=max(ans2,a[i+1]);
        }
    }
    // printf("%d %d\n",ans1,ans2);
    if(ans1==0 && ans2==0) {
        printf("0\n");
        return;
    }
    if(s[1]=='1' && s[n]=='1' && cnt==2) {
        printf("%d\n",max(ans1,ans2)-1);
    } else if(s[1]=='1' || s[n]=='1') {
        printf("%d\n",max(ans1,ans2));
    } else if(s[1]=='0' && s[n]=='0' && cnt==1) {
        printf("%d\n",min(ans1,ans2)+1);
    }else if(s[1]=='0' && s[n]=='0' && cnt==2) {
        printf("%d\n",max(ans1,ans2)-1);
    } else {
        printf("%d\n",min(ans1,ans2));
    }
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}