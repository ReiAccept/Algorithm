#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 3,MAXA=1e9;
const int INF=1e18;

int n,ans,cnt;
int a[MAXN];
int b[65];

void add_bin(int x) {
    int cur=0;
    while(x) {
        if(x&1) {
            b[cur]++;
        }
        x>>=1;
        cur++;
    }
    cnt=max(cur,cnt);
}

int lst() {
    for(int i=0;i<=cnt;i++) {
        if(b[i]!=0) {
            return i;
        }
    }
    return -1;
}

void work()
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        add_bin(a[i]);
    }
    cnt--;
    for(int i=cnt;i>=0;i--) { //DEBUG
        printf("%lld%c", b[i]," \n"[i==0]);
    }
    bool all_same = true;
    for(int i=1;i<=cnt && all_same;i++) {
        if(b[i] != b[0]) {
            all_same = false;
        }
    }
    if(all_same) {
        printf("%lld\n",b[0]);
        return;
    }
    int p=lst();
    while(p!=-1) {

    }
    printf("%lld\n",ans);
}

signed main()
{
    int T; scanf("%lld", &T);
    for (int i = 0; i < T; i++)
    {
        work();
        for(int i=0;i<=cnt;i++) {
            b[i]=0;
        }
        cnt=0;
    }
}