#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e6+3;

int n,cnt;
int a[MAXN],b[MAXN];
char s[MAXN];
// vector<int> p;
int p[MAXN];

bool chk(int x) {
    if(p[1]-1>x) return false;
    if(p[1]-1==x) b[1]=1;
    for(int i=2;i<=cnt;i++) {
        int now=p[i]-p[i-1]-1;
        if(now==0) continue;
        if(b[i-1]) now++;
        if(now/2 + now%2 >x) {
            return false;
        }
        if(now/2==x) {
            if(now%2==0) {
                b[i]=1;
            }
        }
    }
    if(b[cnt]) {
        if(n-p[cnt]+1>x){
            return false;
        }
    } else {
        if(n-p[cnt]>x) {
                return false;
            }
    }
    return true;
}

void work() {
    n=read(); cnt=0;
    // p.clear();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) {
        a[i]=s[i]-'0';
        if(a[i]) {
            // p.emplace_back(i);
            p[++cnt]=i;
        }
        b[i]=0;
    }
    int l=1,r=n,ans=0;
    if(cnt!=n) {
        while(l<=r) {
            int mid=(l+r)>>1;
            for(int i=0;i<=cnt+3;i++) {
                b[i]=0;
            }
            if(chk(mid)) {
                ans=mid;
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
    }
    printf("%lld\n",ans);
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}