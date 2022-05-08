#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 3,MAXA=1e9;
const int INF=1e18;

int n,ans,cnt;
int a[MAXN];
int b[65];
int sum=0;
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
int k[MAXN];

void work()
{
    sum=0;
    scanf("%lld", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lld", a + i);
        sum+=a[i];
        add_bin(a[i]);
    }
    memset(k,0,sizeof(k));
    while(sum) {
        for(int i=1;i<=32;i++) {
            if(sum>=pow(2,i-1)) k[i]++, sum-=pow(2,i-1);
            else break;
        }
    }
    for(int i=1;i<=31;i++) {
        printf("%lld ",k[i]); 
    }
    printf("\n");
    // cnt--;
    printf("%lld\n",k[1]);
    
}

signed main()
{
    int T;
    scanf("%lld", &T);
    for(int i = 0; i < T; i++)
    {
        work();
        for(int i=0;i<=cnt;i++) {
            b[i]=0;
        }
        cnt=0;
    }
}